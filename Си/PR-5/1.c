#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int dirs = 0;
int empty_dirs = 0;
int dirs_only = 0;
int files = 0;
int files_100b_t = 0;
int files_1kb_P = 0;
int files_100kb_txt = 0;

void Poisk(const char *dir_path) 
{
    struct dirent *entry;
    struct stat entry_stat;
    DIR *dir = opendir(dir_path);
    
    if (dir == NULL) 
    {
        perror("Невозможно открыть каталог");
        return;
    }
    
    int is_empty = 1;

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        
        if (stat(path, &entry_stat) == -1) { continue; }

        if (S_ISDIR(entry_stat.st_mode)) 
        {
            dirs++;
            Poisk(path);
            
            if (entry_stat.st_nlink <= 2) 
            {
                empty_dirs++;
            }
            is_empty = 0;
        } 
        else 
        {
            files++;
            if (entry_stat.st_size < 100) 
            {
                if (strchr(entry->d_name, 't')) 
                {
                    files_100b_t++;
                }
            }
            if (entry_stat.st_size > 1024 && entry->d_name[0] == 'P') 
            {
                files_1kb_P++;
            }
            if (entry_stat.st_size < 100 * 1024 && strstr(entry->d_name, ".txt") != NULL) 
            {
                files_100kb_txt++;
            }
        }
    }

    if (is_empty) { dirs_only++; }

    closedir(dir);
}

int main() 
{
    const char *starting_dir = "C:\\C\\PR-5\\Primates";
    
    Poisk(starting_dir);
    
    printf("Количество каталогов: %d\n", dirs);
    printf("Количество пустых каталогов: %d\n", empty_dirs);
    printf("Количество каталогов, содержащих только каталоги: %d\n", dirs_only);
    printf("Количество файлов: %d\n", files);
    printf("Количество файлов, размером меньше 100 B и с 't' в названии: %d\n", files_100b_t);
    printf("Количество файлов, размером больше 1 Kb и название начинающееся с 'P': %d\n", files_1kb_P);
    printf("Количество файлов, размером меньше 100 Kb и с расширением 'txt': %d\n", files_100kb_txt);
    
    return 0;
}