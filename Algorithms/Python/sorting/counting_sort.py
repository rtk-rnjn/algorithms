from __future__ import annotations


def get_min_max(arr: list[int]) -> tuple[int, int]:
    minimum = arr[0]
    maximum = arr[0]

    for num in arr:
        if num < minimum:
            minimum = num
        elif num > maximum:
            maximum = num

    return minimum, maximum


def counting_sort(ls: list[int]) -> list[int]:
    min_value, max_value = get_min_max(arr)

    aux_arr = [0] * (max_value - min_value + 1)

    for i in ls:
        aux_arr[i - min_value] += 1

    for i in range(1, len(aux_arr)):
        aux_arr[i] += aux_arr[i - 1]

    result = [0] * len(ls)

    for i in reversed(ls):
        result[aux_arr[i - min_value] - 1] = i
        aux_arr[i - min_value] -= 1
    return result


if __name__ == "__main__":
    arr = [3, 1, 2, 4, 5, 1, 2, 3]
    print(counting_sort(arr))
