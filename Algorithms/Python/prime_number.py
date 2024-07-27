from __future__ import annotations


def is_prime(number: int) -> bool:
    if number <= 1:
        return False

    if number <= 3:
        return True

    if number % 2 == 0 or number % 3 == 0:
        return False

    i = 5

    while i**2 <= number:
        if number % i == 0 or number % (i + 2) == 0:
            return False
        i += 6

    return True


if __name__ == "__main__":
    print(is_prime(11))  # True
    print(is_prime(12))  # False
