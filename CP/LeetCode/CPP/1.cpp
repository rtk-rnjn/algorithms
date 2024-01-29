// 1. Two Sum

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++)
        {
            int temp = target - nums[i];
            for (int j = i + 1; j < size; j++)
            {
                if (nums[j] == temp)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    int size = (int)result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
}
