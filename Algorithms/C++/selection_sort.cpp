#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        swap(arr[i], arr[min_index]);
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

    selection_sort(array);

    cout << "Sorted array: ";
    for (const int &num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
