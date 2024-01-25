#include <iostream>
#include <vector>

using namespace std;

void binary_search(vector<int> arr, int len, int target)
{
    int left = 0;
    int right = len;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            cout << "Found " << target << " at index " << mid << endl;
            return;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << "Not found " << target << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binary_search(arr, arr.size(), 3);

    return 0;
}
