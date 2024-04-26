#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &arr)
{
    int size = (int)arr.size();
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void print_array(const std::vector<int> &arr)
{
    for (int i : arr)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

void merge(std::vector<int> &arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void tim_sort(std::vector<int> &arr)
{
    const int RUN = 32;
    int n = (int)arr.size();

    for (int i = 0; i < n; i += RUN)
    {
        insertion_sort(arr);
    }

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    std::vector<int> arr = {5, 21, 7, 23, 19, 3, 8, 12, 14, 2};
    tim_sort(arr);
    print_array(arr);

    return 0;
}
