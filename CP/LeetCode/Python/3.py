# 3. Longest Substring Without Repeating Characters

from __future__ import annotations

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Time: O(n)
        # Space: O(n)
        if not s:
            return 0

        ans = 0
        start = 0
        used = {}

        for i, c in enumerate(s):
            if c in used and start <= used[c]:
                start = used[c] + 1
            else:
                ans = max(ans, i - start + 1)

            used[c] = i

        return ans


if __name__ == "__main__":
    sol = Solution()
    s = "abcabcbb"
    print(sol.lengthOfLongestSubstring(s))  # 3
