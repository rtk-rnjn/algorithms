from __future__ import annotations


def sum_of_digits(n: int) -> int:
    """Returns the sum of the digits of a given integer."""
    return sum(int(i) for i in str(n))


if __name__ == "__main__":
    number = 12345
    print(sum_of_digits(number))
