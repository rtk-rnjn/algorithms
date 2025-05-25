# 26. Remove Duplicates from Sorted Array

from __future__ import annotations


class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        # nums[:] = sorted(set(nums))
        # return len(nums)

        # Time: O(n)
        # Space: O(1)

        if not nums:
            return 0

        write_index = 0
        for i in range(1, len(nums)):
            if nums[i] != nums[write_index]:
                write_index += 1
                nums[write_index] = nums[i]

        return write_index + 1


if __name__ == "__main__":
    sol = Solution()
    print(sol.removeDuplicates([1, 1, 2]))  # 2
