#include <iostream>
using namespace std;
void reversearray(int arr[], int s, int e)
{

    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int D;

    cout << "enter the D position " << endl;
    cin >> D;

    D = D % size;

    reversearray(arr, 0, D - 1);
    reversearray(arr, D, size - 1);
    reversearray(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }

    free(arr);
    
    return 0;
}