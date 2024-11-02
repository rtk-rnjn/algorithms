#include <iostream>
#include <vector>

using namespace std;

int sum(const vector<int> &arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

int main()
{
    vector<int> arr = {2, 13, 14, 3, 5};
    int size = (int)arr.size();

    int result = sum(arr, size);

    cout << "Sum of all element is: " << result << endl;
    return 0;
}
