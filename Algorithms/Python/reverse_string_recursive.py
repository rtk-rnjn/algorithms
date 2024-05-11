from __future__ import annotations


def reverse_string_recursive(s: str) -> str:
    """
    Reverse the string using recursion.
    """
    return reverse_string_recursive(s[1:]) + s[0] if s else s


if __name__ == "__main__":
    string = "Hello!"
    print(reverse_string_recursive(string))
