#include <stdio.h>

#define ROW 4
#define COL 4

int row = ROW;
int col = COL;

void spiral_travel(int a[ROW][COL])
{
    int k = 0;
    int l = 0;
    while (k < row && l < col)
    {
        for (int i = l; i < col; i++)
        {
            printf("%d ", a[k][i]);
        }
        k++;
        for (int i = k; i < row; i++)
        {
            printf("%d ", a[i][col - 1]);
        }
        col--;

        if (k < row)
        {
            for (int i = col - 1; i >= l; i--)
            {
                printf("%d ", a[row - 1][i]);
            }
            row--;
        }

        if (l < col)
        {
            for (int i = row - 1; i >= k; i--)
            {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}

int main()
{
    int a[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    spiral_travel(a);
    return 0;
}
