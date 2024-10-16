#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    
    FILE* file1; FILE* file2; FILE* file3;
    char name1[100], name2[100], name3[100];

    printf("¬ведите им€ 1-го файла: ");
    scanf("%s", &name1);

    printf("¬ведите им€ 2-го файла: ");
    scanf("%s", &name2);

    printf("¬ведите им€ конечного файла: ");
    scanf("%s", &name3);

    file1 = fopen(name1, "w");
    file2 = fopen(name2, "w");

    if (file1 == NULL || file2 == NULL)
    {
        perror("ќшибка создани€ файлов");
        return -1;
    }

    char input1[100], input2[100];

    printf("¬ведите данные дл€ 1-го файла: ");
    scanf("%s", &input1);
    
    printf("¬ведите данные дл€ 2-го файла: ");
    scanf("%s", &input2);

    fputs(input1, file1);
    fputs(input2, file2);

    fclose(file1);
    fclose(file2);

    file1 = fopen(name1, "r");
    file2 = fopen(name2, "r");
    file3 = fopen(name3, "w");

    char ch;
    while ((ch = fgetc(file1)) != EOF)
    {
        fputc(ch, file3);
    }

    while ((ch = fgetc(file2)) != EOF)
    {
        fputc(ch, file3);
    }

    fclose(file1); fclose(file2); fclose(file3);
}