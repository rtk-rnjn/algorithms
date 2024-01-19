#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {-1, -11, 5, 6, 7, 9};
    int size = 6;

    int largest = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "The largest element in the arrray is :" << largest << endl;
    return 0;
}