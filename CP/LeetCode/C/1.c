// 1. Two Sum

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target)
{
    int i, j;
    int *result = (int *)malloc(2 * sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
            }
        }
    }
    return result;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;

    int target = 9;

    int *result = twoSum(nums, numsSize, target);
    printf("%d %d\n", result[0], result[1]);
    free(result);

    return 0;
}
