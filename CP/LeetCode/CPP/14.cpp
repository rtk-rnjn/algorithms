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
        int _strs_size = strs.size();
        for (int i = 0; i < _strs_size; i++)
        {
            int _strs_i_size = strs[i].size();

            if (min_size >= _strs_i_size)
            {
                min_size = _strs_i_size;
            }
        }
        string str = "";
        if (_strs_size == 1)
        {
            str = strs[0];
        }
        for (int i = 0; i < min_size; i++)
        {
            for (int j = 0; j < _strs_size - 1; j++)
            {
                if (strs[j][i] == strs[j + 1][i] && !flag)
                {
                    if (j == _strs_size - 2)
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