from __future__ import annotations


def infix_to_postfix(infix: str) -> str:
    stack = []
    postfix = ""

    precedence = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}

    for char in infix:
        if char.isalnum():
            postfix += char
        elif char == "(":
            stack.append(char)
        elif char == ")":
            while stack and stack[-1] != "(":
                postfix += stack.pop()
            stack.pop()
        else:
            while stack and stack[-1] != "(" and precedence[stack[-1]] >= precedence[char]:
                postfix += stack.pop()
            stack.append(char)

    while stack:
        postfix += stack.pop()

    return postfix


if __name__ == "__main__":
    infix = "1+2*3"
    print(infix_to_postfix(infix))  # 123*+
