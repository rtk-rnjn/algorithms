from __future__ import annotations


def reverse_string(s: str) -> str:
    """
    Reverse the string using recursion.
    """
    return s[::-1]


if __name__ == "__main__":
    string = "Hello!"
    print(reverse_string(string))
