#include <stdio.h>

int linear_search(const int arr[], int target, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int length = sizeof(arr) / sizeof(arr[0]);
    int result = linear_search(arr, target, length);

    printf("Index at: %d", result);

    return 0;
}
