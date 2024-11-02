# 150. Evalute Reverse Polish Notation

from __future__ import annotations


class Solution:
    mapper = {
        "+": lambda a, b: a + b,
        "-": lambda a, b: a - b,
        "*": lambda a, b: a * b,
        "/": lambda a, b: int(a / b),
    }
    VALID_TOKENS = set(mapper.keys())

    def evalRPN(self, tokens: list[str]) -> int:
        stack = []

        for token in tokens:
            if token in self.VALID_TOKENS:
                b = stack.pop()
                a = stack.pop()
                stack.append(self.mapper[token](a, b))
            else:
                stack.append(int(token))

        return stack.pop()


if __name__ == "__main__":
    sol = Solution()
    print(sol.evalRPN(["2", "1", "+", "3", "*"]))  # 9
    print(sol.evalRPN(["4", "13", "5", "/", "+"]))  # 6
