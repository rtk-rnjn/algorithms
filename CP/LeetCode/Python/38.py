# 38. Count and Say

from __future__ import annotations


class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"

        prev = self.countAndSay(n - 1)
        res = ""
        count = 1
        for i, number in enumerate(prev):
            if i < len(prev) - 1 and number == prev[i + 1]:
                count += 1
            else:
                res += str(count) + number
                count = 1
        return res


if __name__ == "__main__":
    solution = Solution()
    number = 4
    print(solution.countAndSay(number))
