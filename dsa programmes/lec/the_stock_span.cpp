#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
vector<int> stockspan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int, int>> st; // create a stack to keep track of previous prices and their spans
    for (int i = 0; i < prices.size(); i++)
    {
        int days = 1;                                       // initialize the span to 1
        while (!st.empty() and prices[i] >= st.top().first) // check if the current price is greater than or equal to the previous price
        {
            days = st.top().second + days; // add the previous span to the current span
            st.pop();                      // pop the previous price and span from the stack
        }

        st.push({prices[i], days}); // push the current price and span onto the stack
        ans.push_back(days);        // add the current span to the result vector
    }
    return ans; // return the vector of spans
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = stockspan(arr); // calculate the spans for the input array
    for (auto i : result)
    {
        cout << i << " "; // print the spans
    }

    return 0;
}

/*
The given code implements the Stock Span problem, which is a classic problem in the field of algorithmic trading. The problem is defined as follows:

Given an array of stock prices, find the span of each stock's price, which is defined as the number of consecutive days prior to the current day that the stock's price was less than or equal to the current day's price.

For example, if the input array is {100, 80, 60, 70, 60, 75, 85}, the output should be {1, 1, 1, 2, 1, 4, 6}, since:

On the first day, the span of the stock's price is 1, since there are no previous days on which the stock's price was less than or equal to the current day's price.
On the second day, the span of the stock's price is 1, since the previous day's price was greater than the current day's price.
On the third day, the span of the stock's price is 1, since the previous day's price was greater than the current day's price.
On the fourth day, the span of the stock's price is 2, since the previous two days' prices were less than or equal to the current day's price.
On the fifth day, the span of the stock's price is 1, since the previous day's price was greater than the current day's price.
On the sixth day, the span of the stock's price is 4, since the previous four days' prices were less than or equal to the current day's price.
On the seventh day, the span of the stock's price is 6, since all previous days' prices were less than or equal to the current day's price.
The code uses a stack to keep track of the previous days' prices and their corresponding spans. It iterates through the array of stock prices and for each price, it pops all the prices and their spans from the stack that are less than or equal to the current price, adds up their spans, and pushes the current price and the sum of the spans onto the stack. Finally, it adds the current span to the result vector.

Note that the code defines the integer data type as long long, which allows for larger integer values to be processed. It also uses the fast I/O optimization technique to speed up the input/output operations.

Overall, the code appears to correctly implement the Stock Span problem and should produce the correct output for the given input array.
*/