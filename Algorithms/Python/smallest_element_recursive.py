from __future__ import annotations


def smallest_element_recursive(arr: list[int], n: int) -> int:
    """
    Find the index of the smallest element in the array using recursion.
    """
    if n == 1:
        return 0

    index = smallest_element_recursive(arr, n - 1)
    return index if arr[index] < arr[n - 1] else n - 1


if __name__ == "__main__":
    list_of_numbers = [12, 3, 4, 5, 6, 7, 8, 9, 10]
    print(smallest_element_recursive(list_of_numbers, len(list_of_numbers)))  # 1
