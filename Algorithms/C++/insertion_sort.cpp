#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
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

int main()
{
    vector<int> array = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (const int &num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    insertion_sort(array);

    cout << "Sorted array: ";
    for (const int &num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
