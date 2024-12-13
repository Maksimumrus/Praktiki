#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        perror("Неверное имя файла\n");
        return -1;
    }

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Ошибка создания процесса");
        return -1;
    }

    if (pid == 0)
    {
        execl("./1", "1", argv[1], (char* ) NULL);
        perror("Ошибка");
        exit(1);
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);

        if(WIFEXITED(status))
        {
            int exit_stat = WEXITSTATUS(status);

            if (exit_stat == 0)
            {
                printf("Успешно\n");
            }
            else
            {
                printf("Неудачно");
            }
        }
    }
    return 0;
}