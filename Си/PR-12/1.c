#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void count_txt_files(const char *path) 
{
    struct dirent *entry;
    DIR *dp = opendir(path);
    int count = 0;

    if (dp == NULL) 
    {
        perror("Ошибка открытия папки");
        return;
    }

    while ((entry = readdir(dp)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) 
        {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) 
        {
            pid_t pid = fork();
            if (pid == 0) 
            {
                count_txt_files(full_path);
                exit(0);
            } 
            else if (pid > 0) 
            {
                wait(NULL);
            } 
            else 
            {
                perror("Ошибка создания процесса");
            }
        } 
        else if (entry->d_type == DT_REG) 
        {
            if (strstr(entry->d_name, ".txt") != NULL) 
            {
                count++;
            }
        }
    }

    closedir(dp);
    printf("Папка: %s количество текстовых файлов: %d\n", path, count);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        fprintf(stderr, "Ошибка поиска директоррии %s", argv[0]);
        return EXIT_FAILURE;
    }

    count_txt_files(argv[1]);
    return EXIT_SUCCESS;

    //./PR-12/1 /media/max/Windows/C
}