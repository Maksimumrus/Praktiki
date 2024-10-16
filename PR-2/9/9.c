#include <stdio.h>
#include <locale.h>
#include <string.h>

void sort(char* str)
{
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        for (int j = 0; j < strlen(str)-i-1; j++)
        {
            if(str[j] > str[j+1])
            {
                char temp =  str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file; FILE *file2;
    char str[100];

    file = fopen("9.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    while (fgets(str, 100, file) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        sort(str);
        printf("%s ", str);
    }
    fclose(file);

    return 0;
}