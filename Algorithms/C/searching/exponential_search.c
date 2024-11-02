#include <stdio.h>

int exponential_search(const int *array, int length, int target)
{
    if (array[0] == target)
    {
        return 0;
    }

    int i = 1;

    while (i < length && array[i] <= target)
    {
        i *= 2;
    }

    int low = i / 2;
    int high = i < length ? i : length - 1;

    // Binary search
  
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == target)
        {
            return mid;
        }

        if (array[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(array) / sizeof(array[0]);
    int target = 7;

    int index = exponential_search(array, length, target);

    if (index != -1)
    {
        printf("Element found at index %d\n", index);
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}
