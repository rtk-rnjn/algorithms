#include <stdio.h>

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
