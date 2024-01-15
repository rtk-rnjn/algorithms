#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *arr, int len)
{
    int tmp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
