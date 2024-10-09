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
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int limit = 20;
    int sum = 0;
    int ans = INT_MIN;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if (sum < limit)
    {
        ans = sum;
    }

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        // sum=sum;
        if (sum < limit)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}