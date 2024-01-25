from __future__ import annotations


def string_reverse(string_to_reverse: str) -> str:
    """
    Reverse the string.
    """
    return string_to_reverse[::-1]


if __name__ == "__main__":
    string = "hello"

    # Method 1
    reversed_string = string_reverse(string)
    print(reversed_string)  # olleh

    # Method 2
    reversed_string = "".join(reversed(string))
    print(reversed_string)  # olleh
