# 88. Merge Sorted Array

from __future__ import annotations


class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        write_index = m + n - 1

        m -= 1
        n -= 1

        while m >= 0 and n >= 0:
            if nums1[m] > nums2[n]:
                nums1[write_index] = nums1[m]
                m -= 1
            else:
                nums1[write_index] = nums2[n]
                n -= 1
            write_index -= 1

        while n >= 0:
            nums1[write_index] = nums2[n]
            n -= 1
            write_index -= 1


if __name__ == "__main__":
    nums1 = [1, 2, 3, 0, 0, 0]
    m = 3

    nums2 = [2, 5, 6]
    n = 3

    solution = Solution()
    solution.merge(nums1, m, nums2, n)

    print(nums1)
