# 219. Contains Duplicate II

from __future__ import annotations


class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        indexes = {}
        for index, num in enumerate(nums):
            if num in indexes and abs(index - indexes[num]) <= k:
                return True

            indexes[num] = index
        return False


if __name__ == "__main__":
    s = Solution()
    contains = s.containsNearbyDuplicate([1, 2, 3, 1], 3)

    print(contains)
