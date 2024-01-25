# 1. Two Sum

from __future__ import annotations


class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        # O(n^2) solution
        # for i in range(len(nums)):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             return [i, j]

        # O(n) solution
        d = {}
        for i, num in enumerate(nums):
            if num in d:
                return [d[num], i]
            d[target - num] = i

        return []


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9

    solution = Solution()
    print(solution.twoSum(nums, target))
