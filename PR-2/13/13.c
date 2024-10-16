#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 50

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file; FILE *file2;
    char str[100];

    file = fopen("13_1.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    file2 = fopen("13_2.txt", "w");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    while (fgets(str, 100, file) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        if (strlen(str) < MAX)
        {
            for (size_t i = strlen(str); i < MAX; i++)
            {
                str[i] = ' ';
            }
            str[MAX] = '\0';
        }

        fprintf(file2, "%s\n", str);
    }

    fclose(file);
    fclose(file2);

    return 0;
}