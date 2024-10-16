#include <stdio.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE* f; FILE* newf;

    f = fopen("f.txt", "r");
    newf = fopen("newf.txt", "w");

    if (f == NULL || newf == NULL)
    {
        printf("Ошибка открытия файлов");
        return 1;
    }

    char ch;

    while ((ch = fgetc(f)) != EOF)
    {
        ch = tolower(ch);
        fputc(ch, newf);
    }

    return 0;
}