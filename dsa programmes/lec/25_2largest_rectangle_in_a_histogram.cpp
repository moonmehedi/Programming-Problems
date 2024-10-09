#include <bits/stdc++.h>
using namespace std;

// Macro for faster I/O
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

// Define int as a long long data type
#define int long long

// Define endl as a newline character
#define endl '\n'

// Function to get maximum area of a histogram
int get_maximum_Area(vector<int> v)
{
    int size = v.size();
    int ans = 0;

    // Create a stack to store indices of bars
    stack<int> st;

    // Iterate over all bars of histogram
    int i = 0;
    // We add a dummy bar with zero height at the end of histogram
    v.push_back(0);
    while (i < size + 1)
    {
        // If current bar's height is less than previous bar's height,
        // then the previous bar is the right boundary of current bar.
        while (!st.empty() and (v[st.top()] > v[i]))
        {
            int index = st.top(); // Get the index of the top element
            int height = v[index]; // Get the height of the top element
            st.pop(); // Pop the top element

            // If the stack is empty, then the current bar is the smallest bar,
            // so the maximum area is its height multiplied by its position in the histogram
            if (st.empty())
                ans = max(ans, height * i);

            // Otherwise, calculate the maximum area of a rectangle with the current bar
            // as the smallest bar and with the previous bar as the left boundary.
            // The right boundary is the current bar.
            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, height * len);
            }
        }

        // Push the current bar's index onto the stack
        st.push(i);
        i++;
    }

    // Return the maximum area
    return ans;
}

// Main function
signed main()
{
    fast_io(); // enable faster I/O

    // Input histogram
    vector<int> v = {7, 5, 6, 7, 2, 9};

    // Calculate the maximum area and output it
    cout << get_maximum_Area(v) << endl;

    return 0;
}

/*
This code defines a function get_maximum_Area that takes a vector of integers as input and returns an integer. The function calculates the maximum area of a histogram that can be formed using the input vector.

It creates a stack to keep track of the indices of the input vector. It iterates through the input vector and for each element, it compares it with the elements at the top of the stack.

If the element at the top of the stack is greater than the current element, it pops it from the stack and calculates the area that can be formed using that element as height and the distance between the current index and the new top of the stack as width. It keeps track of the maximum area found so far.

If the current element is greater than or equal to the element at the top of the stack, it pushes the current index onto the stack.

The function also adds a dummy element (0) at the end of the input vector to handle the case where the stack is not empty at the end of the loop.

The main function creates a sample vector and passes it to the get_maximum_Area function. It then prints the returned result.
*/