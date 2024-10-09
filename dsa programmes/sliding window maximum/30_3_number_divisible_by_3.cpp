#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

void print(vector<int> v, pair<int, int> ans)
{
    for (int i = ans.first; i <= ans.second; i++)
    {
        cout << v[i] << " ";
    }
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> v = {84, 23, 45, 12, 56, 82};
    int k = 3, sum = 0;

    pair<int, int> ans;
    // int start = 0, stop = 0;

    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }

    if (sum % 3 == 0)
    {
        print(v, ans = {0, k});
        return 0;
    }

    for (int i = k; i < v.size(); i++)
    {
        sum = sum + v[i] - v[i - k];
        if (sum % 3 == 0)
        {
            print(v, ans = {i - k + 1, i});
            return 0;
        }
    }

    cout << "not found " << endl;

    return 0;
}