#include <stdio.h>
#include <locale.h>
#include <string.h>

int main() 
{
    setlocale(LC_ALL, "RU");
    FILE *file1, *file2;
    char line1[100];
    char line2[100];
    int line_num = 0;

    file1 = fopen("4_1.txt", "r");
    file2 = fopen("4_2.txt", "r");

    if (file1 == NULL) 
    {
        perror("Ошибка открытия первого файла");
        return 1;
    }
    if (file2 == NULL) 
    {
        fclose(file1);
        perror("Ошибка открытия второго файла");
        return 1;
    }

    int found_difference = 0;

    while (fgets(line1, 100, file1) != NULL || fgets(line2, 100, file2) != NULL) 
    {
        line_num++;

        if (strcmp(line1, line2) != 0) 
        {
            int min_length = strlen(line1) < strlen(line2) ? strlen(line1) : strlen(line2);
            for (int i = 0; i < min_length; i++) 
            {
                if (line1[i] != line2[i])
                {
                    printf("Файлы отличаются на строке %d, символ %d\n", line_num, i + 1);
                    found_difference = 1;
                    break;
                }
            }

            if (!found_difference) 
            {
                if (strlen(line1) != strlen(line2)) 
                {
                    printf("Файлы отличаются на строке %d, символ %d\n", line_num, min_length + 1);
                    found_difference = 1;
                }
            }
            break;
        }
    }

    if (!found_difference) 
    {
        if (feof(file1) && feof(file2)) 
        {
            printf("Содержимое файлов полностью совпадает.\n");
        } 
        else if (feof(file1)) 
        {
            printf("Первый файл является началом второго.\n");
        } 
        else 
        {
            printf("Второй файл является началом первого.\n");
        }
    }

    fclose(file1);
    fclose(file2);

    return 0;
}