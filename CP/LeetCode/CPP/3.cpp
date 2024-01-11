// 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        int start = 0;
        int end = 0;
        int len = s.length();
        int hash[256] = {0};
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

int main(void)
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}