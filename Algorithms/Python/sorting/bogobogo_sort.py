from __future__ import annotations

import random


def bogobogo_sort(arr: list[int]) -> list[int]:
    i = 0
    while any(arr[i] > arr[i + 1] for i in range(len(arr) - 1)):
        random.shuffle(arr)
        i += 1

    print(f"Number of iterations: {i}")
    return arr


if __name__ == "__main__":
    arr = [1, 2, 4, 2, 1]
    print(bogobogo_sort(arr))
