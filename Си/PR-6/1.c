#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() 
{
    while (1) 
    {
        FILE *file = fopen("log.txt", "a");
        if (file == NULL) 
        {
            perror("Ошибка открытия файла");
            return 1;
        }
        time_t now = time(NULL);
        fprintf(file, "%s", ctime(&now));
        fclose(file);
        Sleep(1000);
    }
    return 0;
}