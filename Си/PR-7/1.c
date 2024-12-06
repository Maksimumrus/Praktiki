#include <stdio.h>
#include <windows.h>
#include <locale.h>

int main()
{
    char* file = "C:\\C\\PR-7\\1.txt";
    char* user = "User1";
    char cmd[512];

    snprintf(cmd, sizeof(cmd), "runas /user:%s \"notepad.exe %s\"", user, file);

    int result = system(cmd);

    if (result != 0)
    {
        MessageBox(NULL, "Error opening file", "Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    return 0;
}