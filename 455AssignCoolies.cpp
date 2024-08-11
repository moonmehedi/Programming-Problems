#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int lenS = s.size();
        int lenG = g.size();
        int count = 0;
        for (int i = 0, j = 0; i < lenG and j < lenS; j++)
        {
            if (g[i] <= s[j])
            {
                count++;
                i++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    s.findContentChildren({})
}