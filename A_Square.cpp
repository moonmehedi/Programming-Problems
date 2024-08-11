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

    int t;
    cin >> t;
    while (t--)
    {

        pair<int, int> a, b;

        int l;
        bool done = false;
        cin >> a.first >> a.second;

        for (int i = 1; i < 4; i++)
        {
            cin >> b.first >> b.second;

            if (!done and (a.first != b.first and a.second == b.second))
            {
                l = abs(a.first - b.first);
                cout << l * l << endl;
                done = true;
                // g = true;
            }
            else if (!done and (a.first == b.first and a.second != b.second))
            {
                l = abs(a.second - b.second);
                cout << l * l << endl;
                done = true;
                // h = true;
            }
        }
    }
}