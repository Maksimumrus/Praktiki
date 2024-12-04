#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256

int countWords(const char *line) 
{
    int count = 0;
    const char *ch = line;

    while (*ch) 
    {
        while (isspace(*ch)) ch++;
        if (*ch) 
        {
            count++;
            while (*ch && !isspace(*ch)) ch++;
        }
    }
    return count;
}

int main() 
{
    FILE *inputFile = fopen("output1.txt", "r");
    FILE *outputFile = fopen("output2.txt", "w");
    char line[MAX_LINE_LENGTH];

    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Ошибка открытия файла");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)) 
    {
        int wordCount = countWords(line);
        fprintf(outputFile, "%s (%d слов)\n", line, wordCount);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}