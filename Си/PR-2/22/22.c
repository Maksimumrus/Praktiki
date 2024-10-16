#include <stdio.h>
#include <math.h>
#include <locale.h>

int is_square(int num) 
{
    if (num < 0) return 0;
    int kvad = (int)sqrt(num);
    return (kvad * kvad == num);
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    FILE *file = fopen("22.txt", "r");
    if (file == NULL) 
    {
        printf("Ошибка открытия файла.");
        return 1;
    }

    int num;
    int count = 0;
    int nums[100];
    char marks[100] = {0};

    while (fscanf(file, "%d", &num) == 1) 
    {
        nums[count] = num;
        count++;
    }
    fclose(file);

    for (int i = 0; i < count; i++) 
    {
        if (is_square(nums[i])) 
        {
            marks[i] = '-';
        }
        else 
        {
            marks[i] = ' ';
        }
    }

    file = fopen("22.txt", "a");
    if (file == NULL) 
    {
        printf("Ошибка открытия файла.");
        return 1;
    }

    fprintf(file, "\n");
    for (int i = 0; i < count; i++) 
    {
        fprintf(file, "%c", marks[i]);
    }

    fclose(file);
    return 0;
}