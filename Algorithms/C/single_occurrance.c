#include <stdio.h>

int single_occurrance(int *arr, int len)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        result ^= arr[i];
    }

    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Single occurrance: %d\n", single_occurrance(arr, len));
    return 0;
}