#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    int len = 0;

    void fun(vector<int> &candidates, vector<int> &combinations, int target, int count)
    {
        if (count == target)
        {
            ans.push_back(combinations);
            return;
        }
        else if (count > target)
        {
            return;
        }
        else
        {

            for (int i = 0; i < len; i++)
            {
                combinations.push_back(candidates[i]);
                fun(candidates, combinations, target, count = count + candidates[i]);
                count = count - candidates[i];
                combinations.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> combinations;
        len = candidates.size();
        fun(candidates, combinations, target, 0);

        /*simplify ans*/
        // return ans;

        set<multiset<int>> s;

        int anslen = ans.size();
        for (int i = 0; i < anslen; i++)
        {
            int ansvlen = ans[i].size();
            multiset<int> s1;
            for (int j = 0; j < ansvlen; j++)
            {
                s1.insert(ans[i][j]);
            }
            s.insert(s1);
        }

        ans.clear();

        for (auto it : s)
        {
            vector<int> t;
            for (auto it2 : it)
            {
                t.push_back(it2);
            }
            ans.push_back(t);
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<int> v = {2, 3, 5};

    vector<vector<int>> ans = s.combinationSum(v, 8);
    for (auto ele : ans)
    {
        for (auto ele2 : ele)
        {
            cout << ele2 << " ";
        }
        cout << "\n";
    }
}