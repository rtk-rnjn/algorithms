// 20. Valid Parentheses

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s) // NOLINT
    {
        stack<char> st;
        unordered_map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                if (st.top() != m[c])
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("[](])");
    return 0;
}