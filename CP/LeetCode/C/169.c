// 169. Majority Element

#include <stdio.h>

int majorityElement(const int *nums, int numsSize)
{
    int count = 0;
    int possible_majority = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (count == 0)
        {
            possible_majority = nums[i];
        }

        if (nums[i] == possible_majority)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return possible_majority;
}

int main()
{
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result);

    return 0;
}
