#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
bool isvalid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
            st.push(s[i]);
        else
        {
            if (!st.empty() and s[i] == ')' and st.top() == '(')
                st.pop();
            else if (!st.empty() and s[i] == '}' and st.top() == '{')
                st.pop();
            else if (!st.empty() and s[i] == ']' and st.top() == '[')
                st.pop();
            else
                return false;
        }
    }
    if (!st.empty())
        return false;
    else
        return true;
}

signed main()
{
    fast_io(); // enable faster I/O
    string s = "[{{{}}}]]";
    if (isvalid(s))
        cout << "valid" << endl;
    else
        cout << "not valid" << endl;
    return 0;
}