#include <stdio.h>

int replace_element(int *arr, int len, int target, int replacement)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            arr[i] = replacement;
            count++;
        }
    }

    return count;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int replacement = 7;
    int count = replace_element(arr, len, target, replacement);
    printf("Replaced %d elements\n", count);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}