#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// This function calculates the amount of rainwater that can be trapped between a set of bars.
// It takes a vector of integers as its argument, representing the height of each bar.
// It uses a stack to keep track of the index of each bar that is being processed.
// It loops through each bar, comparing it with the bars that have been pushed onto the stack.
// If the current bar is higher than the top bar on the stack, then we know that the water can be trapped between these two bars.
// The function then calculates the width and height of the container, adds the area to the total amount of trapped water, and continues processing the rest of the bars.
int rain_water(vector<int> v)
{
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() and v[st.top()] < v[i])
        {
            int base_index = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            else
            {
                int width = i - st.top() - 1; // here i is right wall st.top left wall
                // This line calculates the width of the container, which is the difference between the index of the current bar and the index of the previous bar on the stack.
                // We subtract 1 from the difference to exclude the two walls themselves.

                ans += (min(v[st.top()], v[i]) - v[base_index]) * width;
                // This line calculates the height of the container, which is the difference between the minimum height of the two walls and the height of the base bar.
                // We multiply this by the width of the container to get the area, and add it to the total amount of trapped water.
            }
        }
        st.push(i); // push the index of the current bar onto the stack
    }
    return ans;
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 4, 0, 0, 4};
    cout << rain_water(a); // print the amount of rainwater that can be trapped between the bars

    return 0;
}

/*
The code you provided is an implementation of the algorithm to find the amount of rainwater that can be trapped between a set of bars. This is done by calculating the area between two bars (walls) and then summing the area for all possible pairs of walls. Here is how the code works:

First, the code defines some macros, one of which changes the data type "int" to "long long". This is done to prevent integer overflow when dealing with large numbers.

The "rain_water" function takes a vector of integers as its argument, representing the height of each bar. It then uses a stack to keep track of the index of each bar that is being processed.

The function loops through each bar in the vector, comparing it with the bars that have been pushed onto the stack. If the current bar is higher than the top bar on the stack, then we know that the water can be trapped between these two bars.

The function then calculates the width of the container (the difference between the index of the current bar and the index of the previous bar on the stack), and the height of the container (the difference between the minimum height of the two walls and the height of the base bar).

The function adds this area to the total amount of trapped water and continues processing the rest of the bars.

Finally, the function returns the total amount of water trapped.

In the "main" function, a vector of integers is defined, representing the height of each bar. The "rain_water" function is called with this vector as its argument, and the result is printed to the console.

Overall, this code is a simple and efficient way to calculate the amount of rainwater that can be trapped between a set of bars.

*/