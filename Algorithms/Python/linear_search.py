from __future__ import annotations


def linear_search(arr: list[int], target: int) -> int:
    for i in enumerate(arr):
        if(i[1] == target):
            return i[0]

    return -1


if __name__ == "__main__":
    numbers = [1, 2, 3, 4, 5, 6] 
    print(linear_search(numbers, 3))  
    print(linear_search(numbers, 7))  