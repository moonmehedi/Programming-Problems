#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        stack<int> st;
        int var=prices[0];
        int max1 = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            // if (max1 < prices[i] - var)
            // {
            //     max1 = prices[i] - var;
            // }

            max1=max(max1,prices[i]-var);

            var=min(var,prices[i]);

            // if (prices[i] < var)
            // {
            //    // st.pop();
            //     var=prices[i];
            // }
        }

        return max1;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 8, 2, 9};
    cout << s.maxProfit(v);
}