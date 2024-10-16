#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");

    int count[100];
    int ch;
    char symbol;
    int max;
    FILE *file;

    file = fopen("2.txt", "r");

    if (file == NULL)
    {
        printf("������ �������� �����"); 
        return 1;
    }        

    while((ch = fgetc(file)) != EOF)
    {
        count[ch]++; 
    }           

    fclose(file);

    for(int i = 0; i < 100; i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            symbol = (char)i;
        }
    }

    printf("�������� ������������� ������: %c, ����������� %d ���", symbol, max);
    
    return 0;
}