#include <stdio.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "RUS");

    FILE *file1, *file2, *temp;
    char str[100];

    file1 = fopen("20_1.txt", "r");
    if (file1 == NULL) 
    {
        printf("������ �������� �����");
        return 1;
    }

    file2 = fopen("20_2.txt", "r");
    if (file2 == NULL) 
    {
        fclose(file1);
        printf("������ �������� �����");
        return 1;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) 
    {
        fclose(file1);
        fclose(file2);
        printf("������ �������� ���������� �����");
        return 1;
    }

    while (fgets(str, sizeof(str), file1) != NULL) 
    {
        fputs(str, temp);
    }

    fclose(temp);
    fclose(file1);

    file1 = fopen("20_1.txt", "w");
    if (file1 == NULL) 
    {
        fclose(file2);
        printf("������ �������� �����");
        return 1;
    }

    while (fgets(str, sizeof(str), file2) != NULL) 
    {
        fputs(str, file1);
    }

    fclose(file2);
    fclose(file1);

    temp = fopen("temp.txt", "r");
    if (temp == NULL) 
    {
        printf("������ �������� ���������� �����");
        return 1;
    }

    file2 = fopen("20_2.txt", "w");
    if (file2 == NULL) 
    {
        fclose(temp);
        printf("������ �������� �����");
        return 1;
    }

    while (fgets(str, sizeof(str), temp) != NULL) 
    {
        fputs(str, file2);
    }

    fclose(temp);
    fclose(file2);

    remove("temp.txt");
    return 0;
}
