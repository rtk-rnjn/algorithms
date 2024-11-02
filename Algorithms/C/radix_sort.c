#include <stdio.h>
#include <stdlib.h>

void radix_sort(int *arr, int n)
{
    int m = arr[0];
    int exp = 1;
    int *b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }

    while (m / exp > 0)
    {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++)
        {
            bucket[arr[i] / exp % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            b[--bucket[arr[i] / exp % 10]] = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = b[i];
        }
        exp *= 10;
    }
    free(b);
}

int main()
{
    int i;
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    radix_sort(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
