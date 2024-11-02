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

void print_matrix(int **matrix, int matrix_size, int matrix_col_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_col_size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void free_matrix(int **matrix, int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int matrix_size = 3;
    int matrix_col_size = 3;
    int **matrix = (int **)malloc(sizeof(int *) * matrix_size);
    for (int i = 0; i < matrix_size; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrix_col_size);
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

    print_matrix(matrix, matrix_size, matrix_col_size);
    rotate(matrix, matrix_size, &matrix_col_size);
    print_matrix(matrix, matrix_size, matrix_col_size);

    free_matrix(matrix, matrix_size);

    return 0;
}
