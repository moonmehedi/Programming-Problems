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

// Function to convert infix expression to postfix expression
string infixtopostfix(string s)
{
    string result;  // The result string
    stack<char> st; // Stack to hold operators and brackets
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z')
            // If current character is an operand, add it to the result string
            result += s[i];
        else if (s[i] == '(') // If current character is an opening bracket, push it to the stack
            st.push(s[i]);
        else if (s[i] == ')') // If current character is a closing bracket
        {
            while (!st.empty() and st.top() != '(')
            // Pop operators from stack and add to result string until opening bracket is found
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) // Pop the opening bracket from the stack
                st.pop();
        }
        else // If current character is an operator
        {
            while (!st.empty() and prec(s[i]) < prec(st.top()))
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
    return result; // Return the final postfix expression
}

signed main()
{
    fast_io();                                 // enable faster I/O
    cout << infixtopostfix("(a-b/c)*(a/k-l)"); // Call the infix to postfix function and output the result
    return 0;
}

/*
This program takes an infix expression as input, converts it into its corresponding postfix expression, and then outputs the postfix expression.

Infix notation is the most common way of writing arithmetic expressions, where operators are written between their operands. For example, the infix expression "(a - b / c) * (a / k - l)" means "subtract b divided by c from a, then multiply the result by subtracting l from a divided by k". However, infix notation is not very suitable for evaluation by a computer program, because it requires explicit parentheses to indicate the order of operations.

Postfix notation, also known as Reverse Polish Notation (RPN), is a notation where operators are written after their operands. For example, the postfix equivalent of the infix expression "(a - b / c) * (a / k - l)" is "abc/-ak/l-*", which means "push a, push b, push c, divide b by c, subtract the result from a, push a, push k, divide a by k, push l, subtract the result from a, multiply the two results".

The infixtopostfix function takes an infix expression as a string input and uses a stack to convert it into postfix notation. It scans the input string from left to right, and for each character, it either appends it to the result string (if it is an operand) or pushes it onto the stack (if it is an opening parenthesis or an operator). When a closing parenthesis is encountered, it pops operators from the stack and appends them to the result string until an opening parenthesis is encountered. When an operator is encountered, it pops operators from the stack and appends them to the result string until an operator with lower precedence or an opening parenthesis is encountered, and then pushes the current operator onto the stack. Finally, when the input string is fully scanned, it pops any remaining operators from the stack and appends them to the result string. The resulting string is the postfix equivalent of the input infix expression.
*/