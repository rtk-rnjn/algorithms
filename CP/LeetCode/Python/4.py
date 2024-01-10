# 4. Median of Two Sorted Arrays

from __future__ import annotations


class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums = sorted(nums1 + nums2)
        n = len(nums)
        return (nums[n//2] + nums[n//2-1]) / 2 if n % 2 == 0 else nums[n//2]
        

if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    print(Solution().findMedianSortedArrays(nums1, nums2))
    # 2.00000

    nums1 = [1, 2]
    nums2 = [3, 4]
    print(Solution().findMedianSortedArrays(nums1, nums2))
    # 2.50000
