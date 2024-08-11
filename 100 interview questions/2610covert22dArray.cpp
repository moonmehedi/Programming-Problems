#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> nums)
    {

        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<vector<int>> ans;
        vector<int> v1, eraselater;
        while (!mp.empty())
        {
            for (auto it = mp.begin(); it != mp.end();)
            {
                if (it->second > 0)
                {
                    v1.push_back(it->first);
                    it->second--;
                }
                if (it->second == 0)
                {
                    eraselater.emplace_back(it);
                    continue;
                }
                it++;
            }
            ans.push_back(v1);
            v1.clear();
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> v = s.findMatrix({1, 3, 4, 1, 2, 3, 1});

    for (auto ele1 : v)
    {
        for (auto ele2 : ele1)
        {
            cout << ele2 << " ";
        }
        cout << endl;
    }
}