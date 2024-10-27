# 11. Container with Most Water

from __future__ import annotations


class Solution:
    def maxArea(self, height: list[int]) -> int:
        # Brute Force
        # max_area = 0
        # for i in range(len(height)):
        #     for j in range(i + 1, len(height)):
        #         max_area = max(max_area, min(height[i], height[j]) * (j - i))
        # return max_area

        # Two Pointer
        max_area = 0
        left, right = 0, len(height) - 1
        while left < right:
            max_area = max(max_area, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area


if __name__ == "__main__":
    sol = Solution()
    print(sol.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
    print(sol.maxArea([1, 1]))
    print(sol.maxArea([4, 3, 2, 1, 4]))
    print(sol.maxArea([1, 2, 1]))
    print(sol.maxArea([1, 2, 4, 3]))

