#include <iostream>
#include <vector>

using namespace std;

void reverse_array(vector<int> &arr, int size)
{
    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int size = arr.size();

    reverse_array(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }

    return 0;
}