#include <bits/stdc++.h>
using namespace std;

// Macro to enable faster input/output
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

// Define int as a long long data type
#define int long long
// Define endline character as '\n'
#define endl '\n'

// Function to check if a given string contains valid brackets
bool isvalid(string s)
{
    bool ans = true; // Initialize answer as true
    stack<char> st;  // Create a stack to store opening brackets

    // Traverse the string
    for (int i = 0; i < s.length(); i++)
    {
        // If the current character is an opening bracket, push it onto the stack
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }
        // If the current character is a closing bracket, check if it matches the top of the stack
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop(); // Pop the matching opening bracket from the stack
            }
            else
            {
                ans = false; // Set answer as false if there is no matching opening bracket
                break;       // Exit the loop
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop(); // Pop the matching opening bracket from the stack
            }
            else
            {
                ans = false; // Set answer as false if there is no matching opening bracket
                break;       // Exit the loop
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop(); // Pop the matching opening bracket from the stack
            }
            else
            {
                ans = false; // Set answer as false if there is no matching opening bracket
                break;       // Exit the loop
            }
        }
    }

    // Check if there are any remaining opening brackets in the stack
    if (!st.empty())
    {
        return false; // If so, set answer as false
    }
    return ans; // Return the final answer
}

signed main()
{
    fast_io(); // Enable faster I/O

    string s = "[{{{}}}]]";
    if (isvalid(s))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "invalid" << endl;
    }

    return 0; // End of program
}

/*
This program checks if a given string containing parentheses, brackets, and braces is valid or not.

The program defines a function isvalid which takes a string s as input and returns a boolean value indicating whether the input string contains valid parentheses, brackets, and braces. The function uses a stack to keep track of opening brackets, and whenever a closing bracket is encountered, it checks whether the top of the stack matches the closing bracket. If they match, it pops the top of the stack; otherwise, the function sets the answer to false and breaks out of the loop.

After the loop is finished, the function checks whether the stack is empty or not. If it's not empty, it means there are unmatched opening brackets, and the function returns false. Otherwise, it returns the answer.

In the main function, the program creates a string s containing the input to be checked, and then calls the isvalid function with s as input. If the function returns true, it prints "valid" to the console; otherwise, it prints "invalid"
*/