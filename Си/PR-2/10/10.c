#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file; FILE *file2;
    char str[100];

    file = fopen("10_1.txt", "r");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    file2 = fopen("10_2.txt", "w");
    if (file == NULL)
    {
        printf("Ошибка открытия"); 
        return 1;
    }

    int num;

    while (fscanf(file, "%d", &num) == 1)
    {
        if (num < 0) {num = 0;}
        fprintf (file2, "%d ", num);
    }

    fclose(file);
    fclose(file2);

    return 0;
}