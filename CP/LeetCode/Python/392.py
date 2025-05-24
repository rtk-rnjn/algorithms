# 392. Is Subsequence

from __future__ import annotations


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # s_len, t_len = len(s), len(t)
        # s_ptr, t_ptr = 0, 0

        # while s_ptr < s_len and t_ptr < t_len:
        #     if s[s_ptr] == t[t_ptr]:
        #         s_ptr += 1
        #     t_ptr += 1

        # return s_ptr == s_len

        if s == "":
            return True

        s_index = 0
        for char in t:
            if char == s[s_index]:
                s_index += 1
                if s_index == len(s):
                    return True

        return False


if __name__ == "__main__":
    s = "abc"
    t = "ahbgdc"

    solution = Solution()
    print(solution.isSubsequence(s, t))  # Output: True

    s = "axc"
    t = "ahbgdc"

    print(solution.isSubsequence(s, t))  # Output: False
