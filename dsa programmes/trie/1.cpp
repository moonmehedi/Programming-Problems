#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

class node
{
public:
    int idx;
    int val;
    node(int idx, int val)
    {
        this->idx = idx;
        this->val = val;
    }
};

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

        vector<node> idx, value;
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
            int result = -1;
            int start = 0;
            int stop = idx.size()-1;
            while (start <= stop)
            {
                int mid = (start + stop) / 2;
                if (idx[i].idx < value[mid].val)
                {
                    result = mid;
                    start = mid + 1;
                }
                else
                {
                    stop = mid - 1;
                }
            }
                count = count + result + 1;
        }
        cout << count << endl;
    }
    return 0;
}