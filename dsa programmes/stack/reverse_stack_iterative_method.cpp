#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
stack<int> reverse(stack<int> &st)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    return temp;
}

signed main()
{
    fast_io(); // enable faster I/O
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st = reverse(st);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }

    return 0;
}