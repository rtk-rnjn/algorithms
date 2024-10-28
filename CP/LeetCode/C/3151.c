// 3151. Special Array I

#include <stdio.h>
#include <stdbool.h>

bool isOdd(int number)
{
    return (number & 1) == 1;
}

bool isArraySpecial(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return true;
    }

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (!(isOdd(nums[i]) ^ isOdd(nums[i + 1])))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    if (isArraySpecial(nums, numsSize))
    {
        printf("Special Array\n");
    }
    else
    {
        printf("Not Special Array\n");
    }

    return 0;
}
