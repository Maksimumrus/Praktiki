#include <stdio.h>
#include <locale.h>

long file_size(const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL) 
    {
        printf("Не удалось открыть файл");
        return -1;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

void replace_file_content(const char *source, const char *destination) 
{
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");
    
    if (src == NULL || dest == NULL) 
    {
        printf("Ошибка при открытии файлов");
        if (src) fclose(src);
        if (dest) fclose(dest);
        return;
    }
    
    char buffer[256];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) 
    {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    char file1[256], file2[256], file3[256];

    printf("Введите имя первого файла: ");
    scanf("%s", file1);

    printf("Введите имя второго файла: ");
    scanf("%s", file2);

    printf("Введите имя третьего файла: ");
    scanf("%s", file3);

    long size1 = file_size(file1);
    long size2 = file_size(file2);
    long size3 = file_size(file3);
    
    if (size1 < 0 || size2 < 0 || size3 < 0) 
    {
        return 1;
    }

    const char *shortest = file1;
    const char *longest = file1;

    if (size2 < size1) {
        shortest = file2;
    }
    if (size3 < size1 && size3 < size2) {
        shortest = file3;
    }

    if (size2 > size1) {
        longest = file2;
    }
    if (size3 > size1 && size3 > size2) {
        longest = file3;
    }

    replace_file_content(shortest, longest);

    printf("Содержимое файла '%s' заменено на содержимое файла '%s'\n", longest, shortest);

    return 0;
}