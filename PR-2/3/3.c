#include <stdio.h>
#include <locale.h>

#define length1 30
#define length2 30

int main() 
{
    setlocale(LC_ALL, "RUS");

    char name[100];
    FILE *file;
    char line[length1 + 1];
    int lengthCount[length2] = {0};

    printf("������� ��� �����: ");
    scanf("%s", name);

    file = fopen(name, "r");
    if (file == NULL) 
    {
        perror("���������� ������� ����");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        int length = 0;
        while (line[length] != '\0' && line[length] != '\n') 
        {
            length++;
        }

        if (length >= 1 && length < length2) 
        {
            lengthCount[length]++;
        }
    }

    fclose(file);

    printf("����:\n");
    for (int i = 1; i < length2; i++) 
    {
        if (lengthCount[i] > 0) 
        {
            printf("������ %d: %d ����������\n", i, lengthCount[i]);
        }
    }

    return 0;
}
