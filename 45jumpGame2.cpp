#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> nums)
    {

        
        int i = 0;
        int range = nums[i] + i;
        int val = range;
        int j = i;
        int r = range;
        int ans = 0;
        int len = nums.size() - 1;

        if (len==0) return 0;

        while (range < len)
        {

            while (i <= range)
            {
                val = i + nums[i];

                if (r < val)
                {
                    r = val;
                    j = i;
                }
                i++;
            }
            ans++;
            i = j;
            range = r;
        }

        return ++ans;
    }
};

int main()
{

    Solution s;
    cout << s.jump({2,0});
}