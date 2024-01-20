#include <stdio.h>

int linear_search_recursive(const int arr[], int target, int length)
{
    if (length == 0)
    {
        return -1;
    }
    if (arr[length - 1] == target)
    {
        return length - 1;
    }
    return linear_search_recursive(arr, target, length - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int length = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search_recursive(arr, target, length);

    printf("Index at: %d", result);

    return 0;
}
