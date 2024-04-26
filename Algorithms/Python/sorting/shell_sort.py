from __future__ import annotations

from typing import TypeVar

T = TypeVar("T", int, float, str)


def shell_sort(array: list[T], shell: int) -> None:
    gap = len(array) // shell
    while gap > 0:
        for i in range(gap, len(array)):
            temp = array[i]
            j = i
            while j >= gap and array[j - gap] > temp:
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= shell


if __name__ == "__main__":
    array = list("SORTEXAMPLE")
    shell_sort(array, 7)
    print(*array)  # Output: [2, 3, 12, 34, 54]
