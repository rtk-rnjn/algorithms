from __future__ import annotations


def binary_search_recursive(arr: list[int], target: int) -> int:
    """
    Binary search algorithm to find the index of the target value in the array.
    If the target value is not in the array, return -1.
    """
    return binary_search_recursive_helper(arr, target, 0, len(arr) - 1)


def binary_search_recursive_helper(arr: list[int], target: int, left: int, right: int) -> int:
    if left > right:
        return -1

    mid = (left + right) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive_helper(arr, target, mid + 1, right)
    else:
        return binary_search_recursive_helper(arr, target, left, mid - 1)
    

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6]
    print(binary_search_recursive(arr, 3))  # 2
    print(binary_search_recursive(arr, 7))  # -1
