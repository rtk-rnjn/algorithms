# 65. Valid Number

from __future__ import annotations


class Solution:
    def isNumber(self, s: str) -> bool:
        # Time complexity of regular expression is O(2^n)
        # Regular expression is not a good solution for this problem

        # import re
        # return bool(re.match(r'^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$', s.strip()))

        s = s.strip()

        seen_expont = seen_dot = seen_digit = False
        for i, c in enumerate(s):
            if c in "+-":
                if i > 0 and s[i - 1] not in "eE":
                    return False
            elif c in "eE":
                if seen_expont or not seen_digit:
                    return False
                seen_expont = True
                seen_digit = False
            elif c == ".":
                if seen_dot or seen_expont:
                    return False
                seen_dot = True
            elif c.isdigit():
                seen_digit = True
            else:
                return False

        return seen_digit


if __name__ == "__main__":
    sol = Solution()
    print(sol.isNumber("0"))  # True
    print(sol.isNumber(" 0.1 "))  # True
    print(sol.isNumber("abc"))  # False
