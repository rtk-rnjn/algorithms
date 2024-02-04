// Roman to Integer

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(const string &s) // NOLINT
    {
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int result = 0;
        int size = (int)s.size();
        for (int i = 0; i < size; i++)
        {
            if (i < s.size() - 1 && map[s[i]] < map[s[i + 1]])
            {
                result -= map[s[i]];
            }
            else
            {
                result += map[s[i]];
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV");
    return 0;
}
