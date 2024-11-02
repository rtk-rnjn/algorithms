from __future__ import annotations


def factorial(number: int) -> int:
    r = 1

    for i in range(1, number + 1):
        r *= i

    return r


if __name__ == "__main__":
    print(factorial(5))
