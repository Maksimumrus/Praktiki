#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file; FILE *temp;
    char str[100];

    char in[100] = "My";
    char out[100] = "Hello";

    file = fopen("8.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    char buffer[1000];
    while (fgets(buffer, 1000, file) != NULL)
    {
        char* pos = buffer;
        while((pos = strstr(pos, in)) != NULL)
        {
            fwrite(buffer, 1, pos-buffer, temp);
            fwrite(out, 1, strlen(out), temp);
            pos += strlen(in);
            strcpy(buffer, pos);
            pos = buffer;
        }
        fputs(buffer, temp);
    }
    fclose(file);
    fclose(temp);

    remove("8.txt");
    rename("temp.txt", "8.txt");

    return 0;
}