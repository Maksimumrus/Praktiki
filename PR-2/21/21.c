#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX 50

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file; FILE *file2;
    char str[100];
    char longest[100];
    int max = 0;

    file = fopen("21.txt", "r");
    if (file == NULL)
    {
        printf("������ ��������"); 
        return 1;
    }

    while (fgets(str, 100, file) != NULL)
    {
        str[strcspn(str, "\n")] = 0;
        if (strlen(str) > max)
        {
            max = strlen(str);
            strcpy(longest, str);
        }
    }

    fclose(file);
    
    if(max > 0) { printf("����� ������ ������: %s, �� ����� - %d", longest, max); }
    else { printf("����� ������ ������ �� �������"); }

    return 0; 
}