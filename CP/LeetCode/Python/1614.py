# 1614. Maximum Nesting Depth of the Parentheses

from __future__ import annotations


class Solution:
    def maxDepth(self, s: str) -> int:
        res = 0
        count = 0
        for i in s:
            if i == "(":
                count += 1
                res = max(res, count)
            elif i == ")":
                count -= 1
        return res


if __name__ == "__main__":
    s = Solution()
    string = "(1+(2*3)+((8)/4))+1"
    print(s.maxDepth(string))
