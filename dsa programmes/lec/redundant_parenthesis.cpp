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

    string s;
    cin >> s;
    bool ans = false;                    // initialize the flag variable to false
    stack<int> st;                       // create an empty stack
    for (int i = 0; i < s.length(); i++) // iterate over each character in the input string
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') // if the current character is an operator
        {
            st.push(s[i]); // push the operator onto the stack
        }
        else if (s[i] == '(') // if the current character is an opening parenthesis
        {
            st.push(s[i]); // push the opening parenthesis onto the stack
        }
        else if (s[i] == ')') // if the current character is a closing parenthesis
        {
            if (st.top() == '(') // if the top of the stack is an opening parenthesis
            {
                ans = true; // set the flag variable to true to indicate redundant parentheses
                break;      // exit the loop since we've already found redundant parentheses
            }
            while (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/') // while the top of the stack is an operator
            {
                st.pop(); // pop the operator from the stack
            }
            st.pop(); // pop the opening parenthesis from the stack
        }
    }
    cout << ans << endl; // output the value of the flag variable

    return 0;
}


/*
the purpose of this code is to find any paranthesis without operator;;
if it founds consequtive paranthesis without operator it will return true;
*/