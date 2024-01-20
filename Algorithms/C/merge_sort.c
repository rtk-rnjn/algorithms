#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int len = right - left + 1;
    int temp[len];
    int index = 0;
    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[index++] = arr[i++];
    }
    while (j <= right)
    {
        temp[index++] = arr[j++];
    }
    for (int k = 0; k < len; k++)
    {
        arr[left++] = temp[k];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, len - 1);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
