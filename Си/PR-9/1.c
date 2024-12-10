#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() 
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output1.txt", "w");
    char line[MAX_LINE_LENGTH];

    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) 
    {
        if (strncmp(line, "03.05.2024", 10) == 0) 
        {
            fputs(line, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}