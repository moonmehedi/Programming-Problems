#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    bool isValid(string s)
    {

        stack<int> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[')
            {
                st.push(s[i]);
            }

            else if (s[i] == ')')
            {
                if (!st.empty() and st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if (s[i] == '}')
            {
                if (!st.empty() and st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
            else if (s[i] == ']')
            {
                if (!st.empty() and st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                    return false;
            }
        }

        if (!st.empty())
        {
            return false;
        }

        return true;
    }
};
int main()
{

    solution s;
    cout << s.isValid("()") << endl;
}