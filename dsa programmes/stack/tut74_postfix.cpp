#include <bits/stdc++.h> // Header file that includes all standard libraries in C++.
using namespace std;


    int postfix_evaluation(string s) // Define a function to evaluate postfix expression.
{
    stack<int> st;                       // Create an empty stack of integers to hold values while evaluating the postfix expression.
    for (int i = 0; i < s.length(); i++) // Loop through the postfix expression string.
    {
        if (s[i] >= '0' and s[i] <= '9') // Check if the current character is a digit.
        {
            st.push(s[i] - '0'); // Convert the character to its integer equivalent and push onto the stack.
        }
        else // If the current character is not a digit, it must be an operator.
        {
            int obj2 = st.top(); // Pop the top two elements of the stack and store them as obj2 and obj1.
            st.pop();
            int obj1 = st.top();
            st.pop();
            switch (s[i]) // Perform the operation corresponding to the operator.
            {
            case '+':                 // Addition.
                st.push(obj2 + obj1); // Push the result onto the stack.
                break;
            case '-': // Subtraction.
                st.push(obj2 - obj1);
                break;
            case '*': // Multiplication.
                st.push(obj2 * obj1);
                break;
            case '/': // Division.
                st.push(obj2 / obj1);
                break;
            }
        }
    }
    return st.top(); // Return the final value on the stack, which represents the result of the postfix expression.
}

signed main() // Entry point of the program.
{
   
    cout << postfix_evaluation("20+45*-7+"); // Call the postfix_evaluation function with the given expression and output the result.

    return 0; // Return 0 to signify successful completion of the program.
}