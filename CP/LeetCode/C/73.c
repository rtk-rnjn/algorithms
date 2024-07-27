// 73. Set Matrix Zeroes

#include <stdlib.h>
#include <stdio.h>

void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int row = matrixSize;
    int col = *matrixColSize;
    int *rowZero = (int *)malloc(sizeof(int) * row);
    int *colZero = (int *)malloc(sizeof(int) * col);
    for (int i = 0; i < row; i++)
    {
        rowZero[i] = 0;
    }
    for (int i = 0; i < col; i++)
    {
        colZero[i] = 0;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowZero[i] = 1;
                colZero[j] = 1;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (rowZero[i] == 1 || colZero[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    free(rowZero);
    free(colZero);
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
    int matrixColSize = 4;
    int **matrix = (int **)malloc(sizeof(int *) * matrixSize);
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * matrixColSize);
    }
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;
    matrix[0][3] = 1;
    matrix[1][0] = 1;
    matrix[1][1] = 0;
    matrix[1][2] = 1;
    matrix[1][3] = 1;
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
    setZeroes(matrix, matrixSize, &matrixColSize);
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixColSize; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    free_matrix(matrix, matrixSize);
    return 0;
}
