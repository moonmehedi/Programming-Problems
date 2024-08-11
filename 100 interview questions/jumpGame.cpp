#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rec(vector<int> &nums, int start, int des, vector<bool> &f)
    {
        if (f[start] == 0)
            return false;

        if (nums[start] == 0)
        {
            return false;
        }
        int me = nums[start] + start;
        if (me >= des)
            return true;

        for (me; me > start; me--)
        {
            if (rec(nums, me, des, f))
            {
                return true;
            }
            f[me] = 0;
        }

        return false;
    }

    bool canJump(vector<int> &nums) // 23114
    {

        int len = nums.size() - 1; // 4
        if (len == 0)
            return true;
        vector<bool> f(len + 1, true);
        return rec(nums, 0, len, f);
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 3, 5, 2, 0, 0, 2, 0, 5, 0, 0, 0, 2, 4, 0, 0, 1, 0};
    cout << s.canJump(nums);
}