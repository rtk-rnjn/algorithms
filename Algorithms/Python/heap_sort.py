from __future__ import annotations


def heap_sort(ls: list[int]) -> list[int]:
    size = len(ls)
    for i in range(size // 2 - 1, -1, -1):
        heapify(ls, size, i)
    for i in range(size - 1, 0, -1):
        ls[i], ls[0] = ls[0], ls[i]
        heapify(ls, i, 0)

    return ls


def heapify(ls: list[int], size: int, index: int) -> None:
    largest = index
    left = 2 * index + 1
    right = 2 * index + 2
    if left < size and ls[left] > ls[largest]:
        largest = left
    if right < size and ls[right] > ls[largest]:
        largest = right
    if largest != index:
        ls[index], ls[largest] = ls[largest], ls[index]
        heapify(ls, size, largest)


if __name__ == "__main__":
    ls = [1, 5, 3, 2, 6, 8, 7, 4]
    heap_sort(ls)
    print(ls)
