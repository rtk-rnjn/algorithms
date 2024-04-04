#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void counting_sort(vector<int> &arr)
{
    int n = (int)arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    vector<int> count(range);
    vector<int> output(n);
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min_val]++;
    }

    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
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

    counting_sort(array);

    cout << "Sorted array: ";
    for (const int &num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
