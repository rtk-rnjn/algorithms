from __future__ import annotations

from typing import TypeVar

T = TypeVar("T", bound=int | float)


def bubble_sort(arr: list[T]) -> list[T]:
    """
    Bubble sort algorithm to sort the array in ascending order.
    """
    for i in range(len(arr)):
        for j in range(len(arr) - 1, i, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]

    return arr


if __name__ == "__main__":
    arr = [2, 5, 3, 1, 4, 6]
    print(bubble_sort(arr))  # [1, 2, 3, 4, 5, 6]
