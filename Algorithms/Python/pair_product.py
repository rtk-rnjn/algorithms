from __future__ import annotations


def pair_product(arr: list[int], target: int) -> tuple[int, int]:
    if len(arr) < 2:
        return -1, -1

    seen = {}
    for i, num in enumerate(arr):
        if target % num == 0 and target // num in seen:
            return seen[target // num], i
        seen[num] = i

    return -1, -1


if __name__ == "__main__":
    print(pair_product([10, 20, 9, 40], 400))  # (1, 3)
    print(pair_product([10, 20, 9, 40], 190))  # (-1, -1)
    print(pair_product([10, 20, 9, 40], 90))  # (0, 2)
