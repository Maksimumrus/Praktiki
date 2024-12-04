#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int file = open("1.txt", O_RDONLY);

    if (file < 0)
    {
        printf("Ошибка открытия файла");
        return -1;
    }
    char line[100];
    ssize_t bytes;

    while((bytes = read(file, line, sizeof(line)-1)) > 0)
    {
        line[bytes] = '\0';
        line[strcspn(line, "\n")] = 0;

        int n = strlen(line);

        for (int i = 0; i < n-1; i++)
        {
            for (int j = i+1; j<n; j++)
            {
                if (line[i] > line[j])
                {
                    char temp = line[i];
                    line[i] = line[j];
                    line[j] = temp;
                }
            }
        }

        printf("Итог:\n");
        printf("%s\n", line);
    }
    close(file);
}