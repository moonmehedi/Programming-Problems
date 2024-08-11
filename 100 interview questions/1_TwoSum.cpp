#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v{3, 2, 4, 54, 22};
    int target;
    cin >> target;
    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        int cmp = target - v[i];
        if (mp[cmp] != 0)
        {
            cout << mp[cmp] - 1 << "," << i;
        }
        mp[v[i]] = i + 1;
    }
}