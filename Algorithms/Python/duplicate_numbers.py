from __future__ import annotations

from typing import TypeVar

T = TypeVar("T")


def duplicate_numbers(arr: list[T]) -> list[T]:
    """
    Print the duplicate numbers in the array.
    """
    seen = set()
    for item in arr:
        if item in seen:
            continue

        count = sum(item == item_ for item_ in arr)
        if count > 1:
            print(f"{item} appears {count} times")

        seen.add(item)

    return arr


if __name__ == "__main__":
    numbers = [1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6]
    duplicate_numbers(numbers)
    # 1 appears 2 times
    # 2 appears 2 times
    # 3 appears 2 times
    # 4 appears 2 times
    # 6 appears 2 times
