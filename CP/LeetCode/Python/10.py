# 10. Regex Matching

from __future__ import annotations

import itertools


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]
        dp[-1][-1] = True

        for i, j in itertools.product(range(len(s), -1, -1), range(len(p) - 1, -1, -1)):
            first_match = i < len(s) and p[j] in {s[i], "."}
            dp[i][j] = dp[i][j + 2] or first_match and dp[i + 1][j] if j + 1 < len(p) and p[j + 1] == "*" else first_match and dp[i + 1][j + 1]
        return dp[0][0]


if __name__ == "__main__":
    sol = Solution()
    print(sol.isMatch("aa", "a"))  # False
    print(sol.isMatch("aa", "a*"))  # True
