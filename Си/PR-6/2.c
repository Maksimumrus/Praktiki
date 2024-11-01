#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define ARCHIVE_DIR "archive"
#define LOG_FILE "log.txt"

void zip_file(const char *zip_filename, const char *file_to_zip) 
{
    char command[512];
    snprintf(command, sizeof(command), "powershell -command Compress-Archive -Path '%s' -DestinationPath '%s'", file_to_zip, zip_filename);
    system(command);
}

int main() 
{
    CreateDirectory(ARCHIVE_DIR, NULL);

    while (1)
     {
        Sleep(5000);

        time_t now = time(NULL);
        struct tm *tm = localtime(&now);

        char archive_file[256];
        strftime(archive_file, sizeof(archive_file), "archive/log_%Y-%m-%d_%H-%M-%S.zip", tm);

        zip_file(archive_file, LOG_FILE);

        DeleteFile(LOG_FILE);
    }

    return 0;
}