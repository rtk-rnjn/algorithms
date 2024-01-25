#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int secondlargest(vector<int> &arr, int size)
{
    int slargest = INT_MIN;
    int largest = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }

        if (largest != arr[i] && slargest < arr[i])
        {
            slargest = arr[i];
        }
    }
    return slargest;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 45, 8, 9, 8};
    int size = arr.size();

    int ans = secondlargest(arr, size);

    cout << "the second largest element in array is :" << ans << endl;

    return 0;
}
