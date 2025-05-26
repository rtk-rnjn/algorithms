// 189. Rotate Array

#include <stdio.h>

void rotate(int *nums, int numsSize, int k)
{
    k = k % numsSize;
    if (k == 0)
    {
        return;
    }

    // Reverse the array in three steps:
    // 1. Reverse the entire array.
    // 2. Reverse the first k elements.
    // 3. Reverse the remaining elements.

    for (int i = 0; i < numsSize / 2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    }

    for (int i = 0; i < k / 2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = temp;
    }

    for (int i = k; i < (numsSize + k) / 2; i++)
    {
        int temp = nums[i];
        nums[i] = nums[numsSize - 1 - (i - k)];
        nums[numsSize - 1 - (i - k)] = temp;
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    rotate(nums, numsSize, k);

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
