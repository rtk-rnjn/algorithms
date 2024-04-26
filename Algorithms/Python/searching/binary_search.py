from __future__ import annotations


def binary_search(arr: list[int], target: int) -> int:
    """
    Binary search algorithm to find the index of the target value in the array.
    If the target value is not in the array, return -1.
    """
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


if __name__ == "__main__":
    numbers = [1, 2, 3, 4, 5, 6]
    print(binary_search(numbers, 3))  # 2
    print(binary_search(numbers, 7))  # -1
