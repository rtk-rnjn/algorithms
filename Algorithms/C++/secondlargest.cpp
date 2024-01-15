#include <iostream>

#include <climits>

using namespace std;
int secondlargest(int arr[], int size)
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

    int arr[] = {4, 5, 6, 7, 45, 8, 9, 8};

    int size = 8;

    int ans = secondlargest(arr, size);

    cout << "the second largest element in array is :" << ans << endl;
}
