// 48. Rotate Image

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = i; j < matrixSize; j++)
        {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize / 2; j++)
        {
            swap(&matrix[i][j], &matrix[i][matrixSize - j - 1]);
        }
    }

    *matrixColSize = matrixSize;
}

void printMatrix(int **matrix, int matrixSize, int matrixColSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void free_matrix(int **matrix, int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int matrixSize = 3;
    int matrixColSize = 3;
    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    printMatrix(matrix, matrixSize, matrixColSize);
    rotate(matrix, matrixSize, &matrixColSize);
    printMatrix(matrix, matrixSize, matrixColSize);

    free_matrix(matrix, matrixSize);

    return 0;
}
