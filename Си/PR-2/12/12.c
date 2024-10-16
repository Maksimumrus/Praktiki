#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file;
    char str[100];
    int count = 0;

    file = fopen("12.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    while (fgets(str, 100, file) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        if (str[0] != "\0" && str[0] == str[strlen(str) - 1])
        {
            count++;
        }
    }

    fclose(file);

    printf("Итог: %d", count);

    return 0;
}