from __future__ import annotations


def partition(arr: list[int], low: int, high: int) -> int:
    """
    Partition the array around the pivot.
    """
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[j], arr[i] = arr[i], arr[j]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quicksort(arr: list[int]) -> list:
    """
    Sort the array using the quicksort algorithm.
    """
    quicksort_helper(arr, 0, len(arr) - 1)
    return arr


def quicksort_helper(arr: list[int], low: int, high: int) -> None:
    """
    Helper function for quicksort.
    """
    if low < high:
        pivot = partition(arr, low, high)
        quicksort_helper(arr, low, pivot - 1)
        quicksort_helper(arr, pivot + 1, high)


if __name__ == "__main__":
    arr = [1, 5, 2, 7, 3, 9, 4, 6, 8]
    print(quicksort(arr))  # [1, 2, 3, 4, 5, 6, 7, 8, 9]
