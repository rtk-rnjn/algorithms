from __future__ import annotations

from typing import TypeVar

T = TypeVar("T", int, float)


def merge_sort(arr: list[T]) -> list[T]:
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])

    return merge(left, right)


def merge(left: list[T], right: list[T]) -> list[T]:
    result = []
    left_index = right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] < right[right_index]:
            result.append(left[left_index])
            left_index += 1
        else:
            result.append(right[right_index])
            right_index += 1

    result.extend(left[left_index:])
    result.extend(right[right_index:])

    return result


if __name__ == "__main__":
    arr = [1, 4, 3, 2, 5, 6]
    print(merge_sort(arr))
