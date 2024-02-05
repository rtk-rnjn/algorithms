# 20. Valid Parentheses

from __future__ import annotations


class Solution:
    def isValid(self, s: str) -> bool:
        # Time: O(n)
        # Space: O(n)
        # stack = []
        # for i in s:
        #     if i in "({[":
        #         stack.append(i)
        #     else:
        #         if not stack:
        #             return False
        #         if i == ")" and stack[-1] != "(":
        #             return False
        #         if i == "}" and stack[-1] != "{":
        #             return False
        #         if i == "]" and stack[-1] != "[":
        #             return False
        #         stack.pop()
        # return not stack

        while "()" in s or "{}" in s or "[]" in s:
            s = s.replace("()", "").replace("{}", "").replace("[]", "")
        return not s


if __name__ == "__main__":
    s = Solution()
    print(s.isValid("()"))  # True
    print(s.isValid("()[]{}"))  # True
    print(s.isValid("(]"))  # False
    print(s.isValid("([)]"))  # False
