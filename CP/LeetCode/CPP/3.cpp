// 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(const string &s) // NOLINT
    {
        int max = 0;
        int start = 0;
        int end = 0;
        int len = (int)s.length();
        vector<int> hash(256);
        while (end < len)
        {
            if (hash[s[end]] == 0)
            {
                hash[s[end]] = 1;
                end++;
            }
            else
            {
                if (end - start > max)
                {
                    max = end - start;
                }
                while (s[start] != s[end])
                {
                    hash[s[start]] = 0;
                    start++;
                }
                start++;
                end++;
            }
        }
        if (end - start > max)
        {
            max = end - start;
        }
        return max;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}