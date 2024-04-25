from __future__ import annotations

import random


def bozo_sort(arr: list[int]) -> list[int]:
    while any(arr[i] > arr[i + 1] for i in range(len(arr) - 1)):
        i, j = random.sample(range(len(arr)), 2)
        arr[i], arr[j] = arr[j], arr[i]
    return arr


if __name__ == "__main__":
    arr = [1, 2, 4, 2, 1]
    print(bozo_sort(arr))
