// 350. Intersection of Two Arrays II

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        while (i < size1 && j < size2)
        {
            if (nums1[i] == nums2[j])
            {

                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution testcase;
    vector<int> result = testcase.intersect(nums1, nums2);
    for (const auto &i : result)
    {
        cout << i << " ";
    }
    return 0;
}
