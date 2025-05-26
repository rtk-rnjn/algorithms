// 153. Find Minimum in Rotated Sorted Array

#include <stdio.h>

int findMin(int *nums, int numsSize)
{
    int low = 0;
    int high = numsSize - 1;

    while (low < high)
    {
        int mid = (high + low) / 2;

        if (nums[mid] > nums[high])
        {
            // The minimum is in the right half
            low = mid + 1;
        }
        else
        {
            // The minimum is in the left half or at mid
            high = mid;
        }
    }
    return nums[low];
}

int main()
{
    int nums[] = {3, 4, 5, 1, 2};
    int numsSize = 5;

    int min = findMin(nums, numsSize);
    printf("The minimum in the rotated sorted array is: %d\n", min);

    return 0;
}