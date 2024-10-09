#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

signed main()
{
    fast_io(); // enable faster I/O
    int n, q, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case " << i + 1 << ":" << endl;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;

            auto ad1 = lower_bound(v.begin(), v.end(), a);
            auto ad2 = upper_bound(v.begin(), v.end(), b);
            cout << ad2 - ad1 << endl;
        }
    }

    return 0;
}