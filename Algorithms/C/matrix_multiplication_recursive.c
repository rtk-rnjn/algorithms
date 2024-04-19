#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[][n], int B[][n], int C[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiply(int n, int A[][n], int B[][n], int C[][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into submatrices
    int new_size = n / 2;
    int A11[new_size][new_size];
    int A12[new_size][new_size];
    int A21[new_size][new_size];
    int A22[new_size][new_size];
    int B11[new_size][new_size];
    int B12[new_size][new_size];
    int B21[new_size][new_size];
    int B22[new_size][new_size];

    int C11[new_size][new_size];
    int C12[new_size][new_size];
    int C21[new_size][new_size];
    int C22[new_size][new_size];

    int P1[new_size][new_size];
    int P2[new_size][new_size];
    int P3[new_size][new_size];
    int P4[new_size][new_size];
    int P5[new_size][new_size];
    int P6[new_size][new_size];
    int P7[new_size][new_size];

    int temp1[new_size][new_size];
    int temp2[new_size][new_size];

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
}

int main()
{
    int n = 4;
    int A[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int B[4][4] = {{17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};
    int C[4][4];

    multiply(n, A, B, C);

    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
