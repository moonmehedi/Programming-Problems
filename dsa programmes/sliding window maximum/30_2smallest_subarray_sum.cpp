#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int smallest_subarray_sum(int arr[], int n, int limit)
{
    int start = 0, end = 0, sum = 0, ans_size = INT_MAX;
    while (end < n)
    {
        if (sum <= limit)
        {
            sum += arr[end++];
        }
        else if (sum > limit)
        {
            ans_size = min(ans_size, abs(start - end ));
            sum -= arr[start++];
        }
    }
    return ans_size;
}

signed main()
{
    fast_io(); // enable faster I/O
    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 51;

    int min = smallest_subarray_sum(arr, n, x);
    cout << min;
    return 0;
}