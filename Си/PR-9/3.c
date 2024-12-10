#include <stdio.h>
#include <ctype.h>

int main() 
{
    FILE *inputFile = fopen("output2.txt", "r");
    char ch;
    int digitCount = 0;

    if (inputFile == NULL) 
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    while ((ch = fgetc(inputFile)) != EOF) 
    {
        if (isdigit(ch)) 
        {
            digitCount++;
        }
    }

    fclose(inputFile);
    printf("Количество цифр в файле: %d\n", digitCount);
    return 0;
}