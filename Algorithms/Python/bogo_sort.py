from __future__ import annotations
import random


def bogo_sort(ls: list[int]) -> list[int]:
    while not is_sorted(ls):
        random.shuffle(ls)

    return ls


def is_sorted(ls: list[int]) -> bool:
    for i in range(len(ls) - 1):
        if ls[i] > ls[i + 1]:
            return False
    return True


if __name__ == "__main__":
    ls = [3, 4, 2, 1, 5]
    print(bogo_sort(ls))
