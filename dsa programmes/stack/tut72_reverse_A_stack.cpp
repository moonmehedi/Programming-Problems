#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr) // Macro to speed up I/O operations

#define int long long // Define int as long long data type
#define endl '\n' // Define endl as a new line character

// Function to insert an element at the bottom of a stack
void insert_at_bottom(stack<int> &st, int ele)
{
    if (st.empty()) // If the stack is empty, push the element
    {
        st.push(ele);
        return;
    }
    int topele = st.top(); // Otherwise, pop the top element
    st.pop();
    insert_at_bottom(st, ele); // Recursively insert the element at the bottom of the stack
    st.push(topele); // Push the top element back onto the stack
}

// Function to reverse the elements of a stack
void reverse_stack(stack<int> &st)
{
    if (st.empty()) // If the stack is empty, return
    {
        return;
    }
    int ele = st.top(); // Otherwise, pop the top element
    st.pop();
    reverse_stack(st); // Recursively reverse the remaining elements of the stack
    insert_at_bottom(st, ele); // Insert the current element at the bottom of the stack
}

signed main() // Main function
{
    fast_io(); // Enable faster I/O

    // Create a stack and push some elements onto it
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    // Print the elements of the stack in the order they were pushed
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    // Push the elements onto the stack again
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    // Reverse the elements of the stack and print them in the new order
    reverse_stack(st);
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;

    return 0; // Exit the program
}