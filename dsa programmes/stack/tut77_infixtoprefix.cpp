#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// Function to determine the precedence of an operator
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' or c == '/')
        return 2;
    else if (c == '+' or c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to prefix expression
string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    string result;  // The result string
    stack<char> st; // Stack to hold operators and brackets
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z')
            // If current character is an operand, add it to the result string
            result += s[i];
        else if (s[i] == ')') // If current character is a closing bracket, push it to the stack
            st.push(s[i]);
        else if (s[i] == '(') // If current character is an opening bracket
        {
            while (!st.empty() and st.top() != ')')
            // Pop operators from stack and add to result string until closing bracket is found
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) // Pop the closing bracket from the stack
                st.pop();
        }
        else // If current character is an operator
        {
            while (!st.empty() and prec(s[i]) <= prec(st.top()))
            // Pop operators from stack and add to result string until operator with lower or equal precedence is found
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]); // Push the current operator to the stack
        }
    }
    while (!st.empty()) // Pop all remaining operators from stack and add to result string
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result; // Return the final prefix expression
}

signed main()
{
    fast_io();                                // enable faster I/O
    cout << infixtoprefix("(a-b/c)*(a/k-l)"); // Call the infix to prefix function and output the result
    return 0;
}
