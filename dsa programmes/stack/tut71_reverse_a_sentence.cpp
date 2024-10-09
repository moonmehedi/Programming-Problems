#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
signed main()
{
    fast_io(); // enable faster I/O
    stack<string> st;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        string word = "";
        while (str[i] != ' ' and str.length() > i)
        {
            word += str[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}