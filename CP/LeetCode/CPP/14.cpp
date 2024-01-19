// Longest common prefix
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min_size = strs[0].size();
        bool flag = false;
        for (int i = 0; i < strs.size(); i++)
        {
            if (min_size >= strs[i].size())
            {
                min_size = strs[i].size();
            }
        }
        string str = "";
        if (strs.size() == 1)
        {
            str = strs[0];
        }
        for (int i = 0; i < min_size; i++)
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j][i] == strs[j + 1][i] && !flag)
                {
                    if (j == strs.size() - 2)
                    {
                        str += strs[0][i];
                    }
                }
                else
                {
                    flag = true;
                }
            }
        }
        return str;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << s.longestCommonPrefix(strs);
    return 0;
}