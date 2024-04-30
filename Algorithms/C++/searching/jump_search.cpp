#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int jump_search(vector<int> &array, int length, int target)
{
    int step = (int)sqrt(length);
    int prev = 0;

    while (array[(int)fmin(step, length) - 1] < target)
    {
        prev = step;
        step += (int)sqrt(length);

        if (prev >= length)
        {
            return -1;
        }
    }

    while (array[prev] < target)
    {
        prev++;

        if (prev == fmin(step, length))
        {
            return -1;
        }
    }

    if (array[prev] == target)
    {
        return prev;
    }

    return -1;
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;

    int index = jump_search(array, (int)array.size(), target);

    if (index != -1)
    {
        cout << "Element found at index " << index << "\n";
    }
    else
    {
        cout << "Element not found\n";
    }

    return 0;
}
