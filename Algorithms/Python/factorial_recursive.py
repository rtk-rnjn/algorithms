from __future__ import annotations


def factorial_recursive(number: int) -> int:
    return 1 if number in {1, 0} else number * factorial_recursive(number - 1)


if __name__ == "__main__":
    print(factorial_recursive(5))  # 120
