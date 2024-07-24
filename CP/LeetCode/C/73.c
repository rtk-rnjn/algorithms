// 73. Set Matrix Zeroes

#include <stdlib.h>

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
