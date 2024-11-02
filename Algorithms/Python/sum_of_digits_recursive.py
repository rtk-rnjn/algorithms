from __future__ import annotations


def sum_of_digits_recursive(n: int) -> int:
    """
    Calculate the sum of digits of a number using recursion.
    """
    return 0 if n == 0 else n % 10 + sum_of_digits_recursive(n // 10)


if __name__ == "__main__":
    print(sum_of_digits_recursive(1213))
