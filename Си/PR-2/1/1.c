#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    FILE *file;
    char str[100], poisk[100];

    printf("������� ��������� ��� ������: ");
    scanf("%s", &poisk);

    file = fopen("1.txt", "r");
    if (file == NULL)
    {
        printf("������ ��������"); 
        return 1;
    }

    while(fgets(str, 100, file) != NULL)    
    {
        if (strstr(str, poisk) != NULL)
        {
            printf("��������� %s �������", poisk);
        }
        
        else { printf("��������� �� �������"); return 1; }
    }

    fclose(file);
    
    return 0;
}