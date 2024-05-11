from __future__ import annotations


def smallest_element(arr: list[int]) -> int:
    """
    Find the smallest element in the array.
    """
    minimum = arr[0]
    index = -1
    for idx, number in enumerate(arr):
        if number < minimum:
            minimum = number
            index = idx
    return index


if __name__ == "__main__":
    list_of_numbers = [12, 3, 4, 5, 6, 7, 8, 9, 10]
    print(smallest_element(list_of_numbers))  # 1
