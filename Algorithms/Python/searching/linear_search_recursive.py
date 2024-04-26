from __future__ import annotations


def linear_search_recursive(arr: list[int], target: int, index: int = 0) -> int:
    if index == len(arr):
        return -1
    if arr[index] == target:
        return index
    return linear_search_recursive(arr, target, index + 1)


if __name__ == "__main__":
    numbers = [1, 2, 3, 9, 4, 5, 6]
    print(linear_search_recursive(numbers, 9))
    print(linear_search_recursive(numbers, 7))
