# 120. Triangle

from __future__ import annotations


class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        n = len(triangle)
        dp = [0] * n
        dp[0] = triangle[0][0]

        for i in range(1, n):
            dp[i] = dp[i - 1] + triangle[i][i]
            for j in range(i - 1, 0, -1):
                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j]
            dp[0] += triangle[i][0]

        return min(dp)


if __name__ == "__main__":
    triangle = [[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]
    sol = Solution()
    print(sol.minimumTotal(triangle))
