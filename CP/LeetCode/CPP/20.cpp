// Valid Parentheses
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> st;
        int flag = 0;
        int string_size = s.size();

        unordered_map<char, char> brackets{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        if ((s[0] == '}' || s[0] == ']' || s[0] == ')'))
        {
            return false;
        }
        if (string_size < 2)
        {
            return false;
        }
        for (int i = 0; i < string_size; i++)
        {
            if (st.empty() && (s[i] == '}' || s[i] == ']' || s[i] == ')'))
            {
                return false;
            }
            if (st.empty() && (s[i] == '[' || s[i] == '{' || s[i] == '('))
            {
                st.push(s[i]);
                flag += 1;
            }
            else if (!st.empty() &&
                     !(s[i] == '[' || s[i] == '{' || s[i] == '('))
            {
                if (brackets[st.top()] != s[i])
                {
                    return false;
                }
                else
                {
                    st.pop();
                    flag -= 1;
                }
            }
            else if ((s[i] == '[' || s[i] == '{' || s[i] == '('))
            {
                st.push(s[i]);
                flag += 1;
            }
        }
        if (flag == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;
    cout << s.isValid("]");
    return 0;
}