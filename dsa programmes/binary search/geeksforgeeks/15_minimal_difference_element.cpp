#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int minimal_difference_element(vector<int> &v, int size, int key)
{
    int high = size - 1;
    int low = 0;
    auto ad = lower_bound(v.begin(), v.end(), key);
    if (*ad == key)
    {
        return ad - v.begin();
    }
    else
    {
        int d1 = *(ad)-key;
        int d2 = key - *(ad - 1);
        if (d1 > d2)
        {
            return (ad - 1) - v.begin();
        }
        else
            return ad - v.begin();
    }
}

signed main()
{
    fast_io(); // enable faster I/O
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int key;
    cin >> key;
    cout << minimal_difference_element(v, n, key) << endl;

    return 0;
}