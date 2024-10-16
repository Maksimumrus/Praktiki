#include <stdio.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RUS");

    FILE *file1, *file2;

    file1 = fopen("15_1.txt", "r");
    file2 = fopen("15_2.txt", "w");
    
    if (file1 == NULL || file2 == NULL) 
    {
        perror("Невозможно открыть файлы");
        return 1;
    }

    double current_num, previous_num;
    int count = 0;

    if (fscanf(file1, "%lf", &previous_num) != 1) 
    {
        fclose(file1);
        fclose(file2);
        return 1;
    }

    count = 0;

    while (fscanf(file1, "%lf", &current_num) == 1) 
    {
        if (current_num < previous_num) 
        {
            count++;
        } 
        else
        {
            if (count > 0) 
            {
                fprintf(file2, "%d ", count + 1);
            }
            count = 0;
        }
        previous_num = current_num;
    }

    if (count > 0) 
    {
        fprintf(file2, "%d ", count + 1);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}