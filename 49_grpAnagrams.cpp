#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        int len = strs.size();
        for (int i = 0; i < len; i++)
        {

            string s = strs[i];

            sort(s.begin(),s.end());

            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto ele : mp)
        {
            ans.push_back(ele.second);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> v{"ddddddddddg", "dgggggggggg"};
    vector<vector<string>> ans = s.groupAnagrams(v);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}