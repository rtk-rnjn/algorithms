// 412. Fizz Buzz

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n)  // NOLINT
    {
        vector<string> result;
        for (int i = 1; i < n + 1; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                result.emplace_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                result.emplace_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                result.emplace_back("Buzz");
            }
            else
            {
                result.push_back(to_string(i));
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> result = s.fizzBuzz(15);
    for (const auto &i : result)
    {
        cout << i << " ";
    }
    return 0;
}
