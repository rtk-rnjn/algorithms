# 17. Letter Combination of a Phone Number

from __future__ import annotations


class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        if not digits:
            return []
        phone = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        res = []
        self.dfs(phone, digits, 0, "", res)
        return res

    def dfs(self, phone, digits, index, path, res):
        if index == len(digits):
            res.append(path)
            return
        for c in phone[digits[index]]:
            self.dfs(phone, digits, index + 1, path + c, res)


if __name__ == "__main__":
    sol = Solution()
    print(sol.letterCombinations("23"))
