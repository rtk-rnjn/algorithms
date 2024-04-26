from __future__ import annotations

import random
from typing import TypeVar

T = TypeVar("T", bound=int | float)


def bogo_sort(ls: list[T]) -> list[T]:
    while not is_sorted(ls):
        random.shuffle(ls)

    return ls


def is_sorted(ls: list[T]) -> bool:
    return all(ls[i] <= ls[i + 1] for i in range(len(ls) - 1))


if __name__ == "__main__":
    numbers = [3, 4, 2, 1, 5]
    print(bogo_sort(numbers))
