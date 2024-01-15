#include <iostream>

using namespace std;

int sum(int arr[], int size)
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
    int arr[] = {2, 13, 14, 3, 5};
    int size = 5;

    int result = sum(arr, size);

    cout << "Sum of all element is: " << result << endl;
    return 0;
}
