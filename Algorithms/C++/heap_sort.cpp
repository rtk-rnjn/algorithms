#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> arr, int size, int i);

void heap_sort(vector<int> arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
}

void heapify(vector<int> arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void print_array(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();

    heap_sort(arr, size);
    print_array(arr, size);
    return 0;
}
