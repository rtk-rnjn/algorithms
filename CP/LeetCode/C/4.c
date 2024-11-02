// 4. Median of Two Sorted Arrays

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(const int *nums1, int nums1Size, const int *nums2, int nums2Size)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int *nums = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    i = 0;
    j = 0;
    k = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            nums[k++] = nums1[i++];
        }
        else
        {
            nums[k++] = nums2[j++];
        }
    }
    while (i < nums1Size)
    {
        nums[k++] = nums1[i++];
    }
    while (j < nums2Size)
    {
        nums[k++] = nums2[j++];
    }

    double median = NAN;
    int mid = (nums1Size + nums2Size) / 2;

    if ((nums1Size + nums2Size) % 2 == 0)
    {
        median = (double)(nums[mid - 1] + nums[mid]) / 2;
    }
    else
    {
        median = nums[mid];
    }

    free(nums);

    return median;
}

int main()
{
    int nums1[] = {1, 3};
    int nums1Size = 2;

    int nums2[] = {2};
    int nums2Size = 1;

    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("%lf\n", median);

    return 0;
}