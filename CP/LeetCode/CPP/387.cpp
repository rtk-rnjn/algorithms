// 387.First Unique Character in a String

// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
        int firstUniqChar(string s)  // NOLINT
        {
            int size = (int)s.size();
            int max = static_cast<unsigned char>(s[0]);
            for (int i = 0; i < size; i++)
            {
                if (static_cast<unsigned char>(s[i]) > max)
                {
                    max = static_cast<unsigned char>(s[i]);
                }
            }
            vector<int> hash(max + 1);
            for (int i = 0; i < max + 1; i++)
            {
                hash[i] = 0;
            }
            for (int i = 0; i < size; i++)
            {
                hash[int(s[i])] += 1;
            }
            for (int i = 0; i < size; i++)
            {
                if (hash[int(s[i])] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
};

int main()
{
    string s = "leetcode";

    Solution testcase;
    int result = testcase.firstUniqChar(s);
    cout << result << endl;
    return 0;
}
