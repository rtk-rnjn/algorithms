#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int> &arr, int shell)
{
    int size = (int)arr.size();
    for (int gap = size / shell; gap > 0; gap /= shell)
    {
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    vector<int> arr = {12, 34, 54, 2, 3};

    shell_sort(arr, 2);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
