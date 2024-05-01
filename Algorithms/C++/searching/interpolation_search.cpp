#include <iostream>
#include <vector>

using namespace std;

int interpolation_search(const vector<int> &array, int length, int target)
{
    int low = 0;
    int high = length - 1;

    while (low <= high && target >= array[low] && target <= array[high])
    {
        if (low == high)
        {
            if (array[low] == target)
            {
                return low;
            }
            return -1;
        }

        int pos = (int)(low + (((double)(high - low) / (array[high] - array[low])) * (target - array[low])));

        if (array[pos] == target)
        {
            return pos;
        }

        if (array[pos] < target)
        {
            low = pos + 1;
        }
        else
        {
            high = pos - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int index = interpolation_search(array, (int)array.size(), target);

    if (index != -1)
    {
        cout<<"Element found at index "<<index<<"\n";
    }
    else
    {
        cout<<("Element not found\n");
    }

    return 0;
}
