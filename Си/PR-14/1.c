#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

typedef struct 
{
    int row;
    int cols;
    int (*matr1)[MAX];
    int (*matr2)[MAX];
    int (*result)[MAX];
} Data;

void* plus(void* arg) 
{
    Data* data = (Data*)arg;
    int row = data->row;
    int cols = data->cols;

    for (int j = 0; j < cols; j++) 
    {
        data->result[row][j] = data->matr1[row][j] + data->matr2[row][j];
    }

    pthread_exit(NULL);
}

int main() 
{
    int rows, cols;

    printf("Введите кол-во строк: ");
    scanf("%d", &rows);

    printf("Введите кол-во столбцов: ");
    scanf("%d", &cols);

    int matr1[MAX][MAX], matr2[MAX][MAX], result[MAX][MAX];
    pthread_t potok[MAX];
    Data data[MAX];

    printf("Введите элементы первой матрицы через пробел:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matr1[i][j]);
        }
    }

    printf("\nВведите элементы второй матрицы через пробел:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matr2[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        data[i].row = i;
        data[i].cols = cols;
        data[i].matr1 = matr1;
        data[i].matr2 = matr2;
        data[i].result = result;

        pthread_create(&potok[i], NULL, plus, (void*)&data[i]);
    }

    for (int i = 0; i < rows; i++) 
    {
        pthread_join(potok[i], NULL);
    }

    printf("\nРезультат:\n");
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}