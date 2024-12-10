#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

#define MAX_BOOKS 10
#define TITLE 100
#define MAX_TRIES 5

typedef struct
{
    char title[TITLE];
    int pages;
} Book;

void lockFile(int fd, char* argv[]) 
{
    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    int tries = 0;
    while (fcntl(fd, F_SETLK, &lock) == -1) 
    {
        if (errno == EACCES || errno == EAGAIN) 
        {
            if (tries++ < MAX_TRIES) 
            {                
                sleep(1);
                continue;
            } 
            printf("%s заблокирован, повторная попытка...\n", argv[1]);           
            exit(2);
        }
        perror(argv[1]);
        exit(3);
    }
}

void unlockFile(int fd) 
{
    struct flock lock;

    lock.l_type = F_UNLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLK, &lock);
}

int Read(char* fileName, Book* book, int hidden, int file)
{
    if (file < 0)
    {
        printf("Ошибка открытия файла\n");
        return -1;
    }

    int count = 0;

    FILE* file1 = fdopen(file, "r");

    while (count < MAX_BOOKS && fscanf(file1, "%s %d", book[count].title, &book[count].pages) == 2)
    {
        if (hidden && count == 1)
        {
            count++;
            fscanf(file1, "%s %d", book[count].title, &book[count].pages);
            continue;
        }
        count++;
    }

    fclose(file1);
    close(file);
    return count;
}

void Print(Book* book, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("%s %d\n", book[i].title, book[i].pages);
    }
}

int main(int argc, char *argv[])
{
    Book book[MAX_BOOKS];
    int count;

    int file = open("1.txt", O_RDONLY);

    lockFile(file, argv);

    count = Read("1.txt", book, 1, file);
    if (count < 0)
    {
        unlockFile(file);
        close(file);
        return -1;
    }

    printf("Книги, где скрыта 3 запись, их количество %d: \n", count);
    Print(book, count);

    close(file);

    // count = Read("1.txt", book, 0, file);
    // if (count < 0)
    // {
    //     return -1;
    // }

    // printf("\n\nКниги, где есть 3 запись, их количество %d \n", count);
    // Print(book, count);

    

    file = open("1.txt", O_RDONLY);

    lockFile(file, argv);

    count = Read("1.txt", book, 1, file);
    if (count < 0)
    {
        unlockFile(file);
        close(file);
        return -1;
    }

    printf("\nКниги, где есть 3 запись, их количество %d: \n", count);
    Print(book, count);

    close(file);

    return 0;
}