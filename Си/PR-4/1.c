#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{

    int file = _open("1.txt", O_RDONLY);
    file + 1;

    if (file < 0) 
    {
        printf("Ошибка при открытии файла: %s\n", strerror(errno));
        return errno;
    }

    _close(file);
    return 0;
}