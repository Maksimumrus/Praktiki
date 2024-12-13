#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int countWords(FILE* file) 
{
    int count = 0;
    char word[100];

    while (fscanf(file, "%s", word) == 1) 
    {
        count++;
    }

    fclose(file);
    return count;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2)
    {
        perror("Неверное имя файла\n");
        return -1;
    }

    FILE* file = fopen("1.txt", "r");

    if (file == NULL) 
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    int count = countWords(file);

    if (count == -1)
    {
        return -1;
    }

    printf("Кол-во слов: %d\n", count);
    return 0;
}