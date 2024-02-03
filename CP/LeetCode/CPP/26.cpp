// Remove duplicates from sorted array
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)  // NOLINT
    {
        int p1 = 1;
        int size = (int)nums.size();
        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[p1] = nums[i];
                p1++;
            }
        }
        return p1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << s.removeDuplicates(nums);
    return 0;
}