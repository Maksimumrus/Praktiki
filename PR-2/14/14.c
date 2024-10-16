#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

int main() 
{
    FILE *file1, *file2;

    file1 = fopen("14_1.txt", "r");
    file2 = fopen("14_2.txt", "w");

    if (file1 == NULL || file2 == NULL) 
    {
        printf("Ошибка открыти файлов");
        return 1;
    }

    char buffer[1024];
    char line[1024];
    int line_length = 0;

    while (fgets(buffer, sizeof(buffer), file1) != NULL) 
    {
        for (int i = 0; i < strlen(buffer); i++) 
        {
            if (buffer[i] != '\n') 
            {
                line[line_length++] = buffer[i];

                if (line_length >= 60 && !strchr(line, '.')) 
                {
                    line[line_length] = '\0';
                    fprintf(file2, "%s\n", line);
                    line_length = 0;
                }

                if (buffer[i] == '.') 
                {
                    line[line_length++] = buffer[i];
                    line[line_length] = '\0';
                    fprintf(file2, "%s\n", line);
                    line_length = 0;
                }
            }
        }
    }

    if (line_length > 0) 
    {
        line[line_length] = '\0';
        fprintf(file2, "%s\n", line);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}