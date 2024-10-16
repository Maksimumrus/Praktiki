#include <stdio.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RUS");
    FILE *file;
    int number;
    int count = 0;

    file = fopen("5.txt", "r");
    if (file == NULL) 
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    while (fscanf(file, "%d", &number) == 1) 
    {
        if (number > 0 && number % 2 == 0) 
        {
            count++;
        }
    }

    fclose(file);
    printf("Количество четных положительных чисел: %d\n", count);

    return 0;
}
