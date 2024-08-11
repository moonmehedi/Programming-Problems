#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ~~for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else if (nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right and nums[left] == triplet[1])
                        left++;
                    while (left < right and nums[right] == triplet[2])
                        right--;
                }
            }
            while (i + 1 < nums.size() and nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = s.threeSum({-1, 0, 1, 2, -1, -4});

    for (auto ele : v)
    {
        for (auto eleInV : ele)
        {
            cout << eleInV << " ";
        }
    }
}