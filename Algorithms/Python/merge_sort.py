def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    left = [0] * (n1)
    R = [0] * (n2)

    for i in range(0, n1):
        left[i] = arr[left + i]

    for j in range(0, n2):
        R[j] = arr[mid + 1 + j]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if left[i] <= R[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = left[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def merge_sort(arr, left, right):
    if left < right:

        m = left + (right - left) // 2

        merge_sort(arr, left, m)
        merge_sort(arr, m + 1, right)
        merge(arr, left, m, right)


arr = [1, 54, 343, 523]
merge_sort(arr, 0, len(arr) - 1)

print(arr)
