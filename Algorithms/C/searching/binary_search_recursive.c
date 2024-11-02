#include <stdio.h>

void binary_search(const int arr[], int left, int right, int target)
{
    if (left > right)
    {
        printf("Not found %d\n", target);
        return;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == target)
    {
        printf("Found %d at index %d\n", target, mid);
        return;
    }
    if (arr[mid] < target)
    {
        binary_search(arr, mid + 1, right, target);
    }
    else
    {
        binary_search(arr, left, mid - 1, target);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    binary_search(arr, 0, len - 1, 3);
    binary_search(arr, 0, len - 1, 7);
    return 0;
}
