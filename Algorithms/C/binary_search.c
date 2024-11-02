#include <stdio.h>

void binary_search(const int arr[], int length, int target) // NOLINT // cppcheck-suppress constParameter
{
    int left = 0;
    int right = length;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            printf("Found %d at index %d\n", target, mid);
            return;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("Not found %d\n", target);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    binary_search(arr, len, 3);

    return 0;
}
