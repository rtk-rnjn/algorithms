#include <iostream>

using namespace std;

void binary_search(int *arr, int len, int target)
{
    int left = 0, right = len - 1;
    int mid;

    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            printf("Found %d at index %d\n", target, mid);
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

    cout << "Not found" << target;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    binary_search(arr, 10, 4);

    return 0;
}
