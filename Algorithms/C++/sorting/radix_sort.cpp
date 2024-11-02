#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radix_sort(vector<int> &arr)
{
    int n = (int)arr.size();
    int max_val = *max_element(arr.begin(), arr.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10)
    {
        vector<int> output(n);
        vector<int> count(10);

        for (int i = 0; i < n; i++)
        {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
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

    radix_sort(array);

    cout << "Sorted array: ";
    for (const int &num : array)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
