#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return x < y ? x : y;
}

void insertion_sort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    int *left_arr = (int *)malloc(len1 * sizeof(int));
    int *right_arr = (int *)malloc(len2 * sizeof(int));

    for (int i = 0; i < len1; i++)
    {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < len2; i++)
    {
        right_arr[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < len1 && j < len2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k++] = left_arr[i++];
        }
        else
        {
            arr[k++] = right_arr[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = left_arr[i++];
    }
    while (j < len2)
    {
        arr[k++] = right_arr[j++];
    }

    free(left_arr);
    free(right_arr);
}

void tim_sort(int arr[], int n)
{
    int min_run = 32;
    for (int i = 0; i < n; i += min_run)
    {
        insertion_sort(arr, i, min((i + min_run - 1), (n - 1)));
    }

    for (int size = min_run; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1, 6, 7, 8, 9, 10, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    tim_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
