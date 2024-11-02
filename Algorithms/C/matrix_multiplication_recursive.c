#include <stdio.h>
#include <stdlib.h>

void free_matrix(int n, int **matrix);

void add(int n, int **A, int **B, int **C) // NOLINT
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int **A, int **B, int **C) // NOLINT
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

int **allocate(const int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
    return matrix;
}

void multiply(int n, int **A, int **B, int **C) // NOLINT
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into submatrices
    int new_size = n / 2;
    int **A11 = allocate(new_size);
    int **A12 = allocate(new_size);
    int **A21 = allocate(new_size);
    int **A22 = allocate(new_size);
    int **B11 = allocate(new_size);
    int **B12 = allocate(new_size);
    int **B21 = allocate(new_size);
    int **B22 = allocate(new_size);

    int **C11 = allocate(new_size);
    int **C12 = allocate(new_size);
    int **C21 = allocate(new_size);
    int **C22 = allocate(new_size);

    int **P1 = allocate(new_size);
    int **P2 = allocate(new_size);
    int **P3 = allocate(new_size);
    int **P4 = allocate(new_size);
    int **P5 = allocate(new_size);
    int **P6 = allocate(new_size);
    int **P7 = allocate(new_size);

    int **temp1 = allocate(new_size);
    int **temp2 = allocate(new_size);

    // Divide matrix A into 4 submatrices
    for (int i = 0; i < new_size; i++)
    {
        for (int j = 0; j < new_size; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + new_size];
            A21[i][j] = A[i + new_size][j];
            A22[i][j] = A[i + new_size][j + new_size];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + new_size];
            B21[i][j] = B[i + new_size][j];
            B22[i][j] = B[i + new_size][j + new_size];
        }
    }

    // Calculate P1 to P7
    add(new_size, A11, A22, temp1);
    add(new_size, B11, B22, temp2);
    multiply(new_size, temp1, temp2, P1);

    add(new_size, A21, A22, temp1);
    multiply(new_size, temp1, B11, P2);

    subtract(new_size, B12, B22, temp1);
    multiply(new_size, A11, temp1, P3);

    subtract(new_size, B21, B11, temp1);
    multiply(new_size, A22, temp1, P4);

    add(new_size, A11, A12, temp1);
    multiply(new_size, temp1, B22, P5);

    subtract(new_size, A21, A11, temp1);
    add(new_size, B11, B12, temp2);
    multiply(new_size, temp1, temp2, P6);

    subtract(new_size, A12, A22, temp1);
    add(new_size, B21, B22, temp2);
    multiply(new_size, temp1, temp2, P7);

    // Calculate C11, C12, C21, C22
    add(new_size, P1, P4, temp1);
    subtract(new_size, temp1, P5, temp2);
    add(new_size, temp2, P7, C11);

    add(new_size, P3, P5, C12);

    add(new_size, P2, P4, C21);

    add(new_size, P1, P3, temp1);
    subtract(new_size, temp1, P2, temp2);
    add(new_size, temp2, P6, C22);

    // Combine submatrices into C
    for (int i = 0; i < new_size; i++)
    {
        for (int j = 0; j < new_size; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + new_size] = C12[i][j];
            C[i + new_size][j] = C21[i][j];
            C[i + new_size][j + new_size] = C22[i][j];
        }
    }

    free_matrix(new_size, A11);
    free_matrix(new_size, A12);
    free_matrix(new_size, A21);
    free_matrix(new_size, A22);
    free_matrix(new_size, B11);
    free_matrix(new_size, B12);
    free_matrix(new_size, B21);
    free_matrix(new_size, B22);

    free_matrix(new_size, C11);
    free_matrix(new_size, C12);
    free_matrix(new_size, C21);
    free_matrix(new_size, C22);

    free_matrix(new_size, P1);
    free_matrix(new_size, P2);
    free_matrix(new_size, P3);
    free_matrix(new_size, P4);
    free_matrix(new_size, P5);
    free_matrix(new_size, P6);
    free_matrix(new_size, P7);

    free_matrix(new_size, temp1);
    free_matrix(new_size, temp2);
}

void free_matrix(int n, int **matrix)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    int n = 4;
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[4][4] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

    int **A_matrix = allocate(n);
    int **B_matrix = allocate(n);
    int **C_matrix = allocate(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A_matrix[i][j] = A[i][j];
            B_matrix[i][j] = B[i][j];
        }
    }

    multiply(n, A_matrix, B_matrix, C_matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", C_matrix[i][j]);
        }
        printf("\n");
    }

    free_matrix(n, A_matrix);
    free_matrix(n, B_matrix);
    free_matrix(n, C_matrix);

    return 0;
}
