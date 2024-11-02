#include <iostream>
#include <vector>

using namespace std;

void reversearray(vector<int> &arr, int start, int end)
{
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
    int size = (int)arr.size();
    int d = 2;

    d = d % size;

    reversearray(arr, 0, d - 1);
    reversearray(arr, d, size - 1);
    reversearray(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }

    return 0;
}
