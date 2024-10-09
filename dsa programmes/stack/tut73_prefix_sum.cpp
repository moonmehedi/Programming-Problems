#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

/*
                            WHAT THIS PROGRAM DO
This is a C++ program that evaluates a prefix expression using a stack data structure.

The prefix expression is a mathematical notation where each operator is placed before its two operands. For example, the prefix form of the expression "2 + 3" is "+ 2 3".

To evaluate a prefix expression, the program reads the expression from right to left and uses a stack to keep track of the operands and operators. When it encounters an operand (a digit), it pushes it onto the stack. When it encounters an operator, it pops the top two operands from the stack, applies the operator to them, and pushes the result back onto the stack.

In this program, the main function calls the prefix_evaluation function, which takes a string argument (the prefix expression) and returns the result of the evaluation.

The prefix_evaluation function uses a stack<int> to store the operands. It iterates over the string from right to left, and for each character, it checks if it is a digit or an operator. If it is a digit, it converts it to an integer and pushes it onto the stack. If it is an operator, it pops the top two operands from the stack, applies the operator to them, and pushes the result back onto the stack.

The program uses the pow function from the cmath library to handle exponentiation.

The program also defines the fast_io macro, which disables synchronization between the standard input/output streams and the C standard library streams, and unties the input and output streams. This can result in faster I/O operations.

Finally, the program sets the int data type to be a long long using the preprocessor #define directive. This ensures that the program can handle larger numbers without overflowing.

Overall, this program provides a simple and efficient way to evaluate prefix expressions using a stack data structure




*/

#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr) // Macro to speed up I/O operations

#define int long long // Define int as long long data type
#define endl '\n'     // Define endl as a new line character

int prefix_evalutation(string s) // Function to evaluate prefix expression
{
    stack<int> st;                            // Create an empty stack to store operands
    for (int i = s.length() - 1; i >= 0; i--) // Loop through the expression from right to left
    {
        if (s[i] >= '0' and s[i] <= '9') // If the character is a digit
        {
            st.push(s[i] - '0'); // Push the digit onto the stack
        }
        else // If the character is an operator
        {
            int obj1 = st.top(); // Pop the top operand from the stack
            st.pop();
            int obj2 = st.top(); // Pop the second operand from the stack
            st.pop();
            switch (s[i]) // Apply the operator to the operands
            {
            case '+': // Addition
                st.push(obj1 + obj2);
                break;

            case '-': // Subtraction
                st.push(obj1 - obj2);
                break;
            case '*': // Multiplication
                st.push(obj1 * obj2);
                break;
            case '^': // Exponentiation
                st.push(pow(obj1, obj2));
                break;
            case '/': // Division
                st.push(obj1 / obj2);
                break;
            }
        }
    }
    return st.top(); // Return the final result
}

signed main() // Main function
{
    fast_io();                                       // Enable faster I/O
    cout << prefix_evalutation("-+7*45+20") << endl; // Evaluate the expression and print the result
    return 0;                                        // Exit the program
}