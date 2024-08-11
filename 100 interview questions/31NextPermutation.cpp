#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int stop)
    {
        for (; start < stop; start++, stop--)
        {
            swap(nums[start], nums[stop]);
        }
    }

    void nextPermutation(vector<int> &nums)
    {

        int i = nums.size() - 1;

        for (i; i > 0; i--)
        {
            if (nums[i - 1] < nums[i])
            {

                int j = nums.size() - 1;
                for (j; nums[j] < nums[i - 1]; j--)

                    swap(nums[i - 1], nums[j]);
                reverse(nums, i, nums.size() - 1);
                return;
            }
        }

        reverse(nums, 0, (nums.size() - 1));
    }
};

int main()
{
    Solution s;
    s.nextPermutation({2, 1, 3});
}