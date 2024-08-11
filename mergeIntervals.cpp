#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int len = intervals.size() - 1;
        pair<int, int> start, stop;
        int a, b;
        int i = 0;
        while (i < len)
        {
            start = {i, 0}, stop = {i, 0};
            a = intervals[i][0];
            b = -1;
            while (i < len and intervals[i][1] >= intervals[i + 1][0])
            {
                a = max(intervals[i + 1][0], a);

                stop = {i + 1, 1};
                b = max(intervals[])
                    i++;
            }
            if (start != stop)
            {
                ans.push_back({intervals[start.first][start.second], intervals[stop.first][stop.second]});
                if (i == len)
                    return ans;
                i++;
            }
            else
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};
int main()
{

    vector<vector<int>> ans;

    Solution s;
    s.merge()
}