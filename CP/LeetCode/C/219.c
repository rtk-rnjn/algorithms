// 219. Contains Duplicate II

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

bool containsNearbyDuplicate(const int nums[], int numsSize, int k)
{
    int *arr = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        arr[i] = nums[i];
    }
    qsort(arr, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            for (int j = 0; j < numsSize; j++)
            {
                if (nums[j] == arr[i])
                {
                    for (int m = j + 1; m < numsSize; m++)
                    {
                        if (nums[m] == arr[i] && m - j <= k)
                        {
                            free(arr);
                            return true;
                        }
                    }
                }
            }
        }
    }

    free(arr);

    return false;
}

int main()
{
    int nums[] = {1, 2, 3, 1};
    int k = 3;
    printf("%d\n", containsNearbyDuplicate(nums, 4, k));

    return 0;
}
