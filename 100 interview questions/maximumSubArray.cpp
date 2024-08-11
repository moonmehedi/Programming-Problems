#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxSum;
    }
};

int main()
{
    Solution s;
    vector<int> v{1};
    cout << s.maxSubArray(v);
}