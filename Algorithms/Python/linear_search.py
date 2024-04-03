from __future__ import annotations


def linear_search(arr: list[int], target: int) -> int:
    for index, value in enumerate(arr):
        if value == target:
            return index

    return -1


if __name__ == "__main__":
    numbers = [1, 2, 3, 9, 4, 5, 6]
    print(linear_search(numbers, 9))
    print(linear_search(numbers, 7))
