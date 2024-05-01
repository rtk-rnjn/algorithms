#include <iostream>
#include <vector>

using namespace std;

void duplicate_numbers(vector<int> &arr)
{
    int len = arr.size();
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        for (int j = 0; j < len; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > 1)
        {
            cout << arr[i] << " appears " << count << " times\n";
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1, 6, 6};

    duplicate_numbers(arr);

    return 0;
}
