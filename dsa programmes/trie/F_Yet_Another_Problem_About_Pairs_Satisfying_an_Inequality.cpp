#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)


bool mycomparator(node v1, node v2)
{
    return v1.val > v2.val;
}
signed main()
{
    fast_io();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<pair<int>> idx, value;
        for (int i = 1; i < n + 1; i++)
        {
            int val;
            cin >> val;
            if (i > val)
            {
                idx.push_back(node(i, val));
                value.push_back(node(i, val));
            }
        }
        sort(value.begin(), value.end(), mycomparator);

        int count = 0;
        for (int i = 0; i < idx.size(); i++)
        {
            int j = 0;
            while (idx[i].idx < value[j].val)
            {
                count++;
                j++;
            }
        }
        cout << count << endl;
    }
    return 0;
}