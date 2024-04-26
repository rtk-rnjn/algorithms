#include <iostream>
#include <vector>

using namespace std;

int binary_search_helper(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] > target)
    {
        return binary_search_helper(arr, target, low, mid - 1);
    }

    return binary_search_helper(arr, target, mid + 1, high);
}

int binary_search(vector<int> &arr, int target)
{
    return binary_search_helper(arr, target, 0, (int)arr.size() - 1);
}

int main()
{
    vector<int> nums = {3, 4, 6, 7, 8, 10, 12};
    int target = 10;
    int target_index = binary_search(nums, target);
    if (target_index != -1)
    {
        cout << "Element found at index " << target_index;
    }
    else
    {
        cout << "Element not found";
    }

    return 0;
}
