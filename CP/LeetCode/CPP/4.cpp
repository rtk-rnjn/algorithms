// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) // NOLINT
    {
        // Time Complexity: O(n)
        // Space Complexity: O(n)

        vector<int> nums;
        int i = 0;
        int j = 0;

        int size1 = (int)nums1.size();
        int size2 = (int)nums2.size();

        while (i < size1 && j < size2)
        {
            if (nums1[i] < nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while (i < size1)
        {
            nums.push_back(nums1[i]);
            i++;
        }
        while (j < size2)
        {
            nums.push_back(nums2[j]);
            j++;
        }

        int n = (int)nums.size();

        if (n % 2 == 0)
        {
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }

        return nums[n / 2];
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {0, 0};
    nums2 = {0, 0};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {};
    nums2 = {1};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    nums1 = {2};
    nums2 = {};
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}