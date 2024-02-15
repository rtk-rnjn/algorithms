from __future__ import annotations

from typing import TypeVar

T = TypeVar("T", bound=int | float)


def insertion_sort(arr: list[T]) -> None:
    """Insertion sort algorithm to sort the array in ascending order."""
    n = len(arr)
    if n <= 1:
        return

    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 15, 2, 7]  # Input array: Unsorted
    insertion_sort(arr)
    print("Sorted array:", arr)  # Output: Sorted array: [2, 5, 6, 7, 11, 12, 13, 15]
