from __future__ import annotations


def insertion_sort(array: list[int]) -> list[int]:
    """Sort an array using the insertion sort algorithm."""
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key
    return array


def merge(left: list[int], right: list[int]) -> list[int]:
    """Merge two sorted arrays."""
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def tim_sort(array: list[int], run: int = 32) -> list[int]:
    """Sort an array using the Tim sort algorithm."""
    for i in range(0, len(array), run):
        array[i : i + run] = insertion_sort(array[i : i + run])
    size = run
    while size < len(array):
        for left in range(0, len(array), 2 * size):
            mid = left + size - 1
            right = min(left + 2 * size - 1, len(array) - 1)
            array[left : right + 1] = merge(array[left : mid + 1], array[mid + 1 : right + 1])
        size *= 2
    return array
