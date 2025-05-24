// 27. Remove Element

#include <stdio.h>

int removeElement(int *nums, int numSize, int val)
{
    int index = 0;

    for (int i = 0; i < numSize; i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

int main()
{
    int nums[] = {3, 2, 2, 3};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int newLength = removeElement(nums, numSize, val);

    printf("New length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}