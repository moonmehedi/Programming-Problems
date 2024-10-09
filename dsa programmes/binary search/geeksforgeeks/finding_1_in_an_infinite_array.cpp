#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int find_index_of_one(const vector<int> &v)
{
    int l = 0;
    int h = 1;
    while (v[h] == 0)
    {
        l = h;
        h = h * 2;
    }
    int mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (v[mid] == 1)
        {
            h = mid - 1;
        }
        else if (v[mid] < 1)
        {
            l = mid + 1;
        }
        else if (v[mid] > 1)
        {
            h = mid - 1;
        }
    }
    return mid + 1;
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> v = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    cout << find_index_of_one(v) << endl;

    return 0;
}