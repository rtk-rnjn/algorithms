#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &arr)
{
    int size = (int)arr.size();
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arr.size(); i += 1)
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

    shellSort(arr);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
