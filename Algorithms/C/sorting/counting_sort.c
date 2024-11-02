#include <stdio.h>
#include <stdlib.h>

void init_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

int *counting_sort(const int *arr, int size)
{
    int *sorted = (int *)malloc(size * sizeof(int));
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    int *count = (int *)malloc((max + 1) * sizeof(int));
    init_arr(count, max + 1);

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    free(count);
    return sorted;
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *sorted = counting_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", sorted[i]);
    }
    printf("\n");
    free(sorted);
    return 0;
}
