// 88. Merge Sorted Array

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, const int* nums2, int nums2Size, int n) {
    if (nums1 == NULL || nums2 == NULL || m < 0 || n < 0 || nums1Size < m + n) {
        return;
    }

    if (nums2Size == 0) {
        return;
    }

    int write_index = m + n - 1;
    int num1_index = m - 1;
    int num2_index = n - 1;

    while ((num1_index >= 0) && (num2_index >= 0)) {
        if (nums1[num1_index] > nums2[num2_index]) {
            nums1[write_index] = nums1[num1_index];
            num1_index--;
        } else {
            nums1[write_index] = nums2[num2_index];
            num2_index--;
        }
        write_index--;
    }

    while (num2_index >= 0) {
        nums1[write_index] = nums2[num2_index];
        num2_index--;
        write_index--;
    }
}

int main() {
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums1Size = 6;
    int m = 3;

    int nums2[] = {2, 5, 6};
    int nums2Size = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);
    for (int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}