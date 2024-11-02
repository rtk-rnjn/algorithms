from __future__ import annotations


def radix_sort(arr: list[int]) -> None:
    if not arr:
        return

    base = 10
    max_num = max(arr)
    exp = 1

    while max_num // exp > 0:
        counting_sort(arr, exp, base)
        exp *= base


def counting_sort(arr: list[int], exp: int, base: int) -> None:
    n = len(arr)
    output = [0] * n
    count = [0] * base

    for num in arr:
        count[(num // exp) % base] += 1

    for i in range(1, base):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        output[count[(arr[i] // exp) % base] - 1] = arr[i]
        count[(arr[i] // exp) % base] -= 1

    for i in range(n):
        arr[i] = output[i]


if __name__ == "__main__":
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    radix_sort(arr)
    print(arr)  # Output: [2, 24, 45, 66, 75, 90, 170, 802]
