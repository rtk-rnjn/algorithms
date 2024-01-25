// Roman to Integer
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    int romanToInt(string s)
    {
        int result = 0;
        unordered_map<char, int> symbol{{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};

        int size = s.size();
        for (int i = 0; i < size - 1; i++)
        {
            if (symbol[s[i]] < symbol[s[i + 1]])
            {
                result -= symbol[s[i]];
            }
            else
            {
                result += symbol[s[i]];
            }
        }
        result += symbol[s[size - 1]];
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV");
    return 0;
}
