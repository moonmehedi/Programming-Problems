#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int is_possible(int arr[], int n, int mid)
{
    int sum = 0, count = 1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            sum = arr[i];
            count++;
        }
    }
    return count;
}

signed main()
{
    fast_io(); // enable faster I/O

    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / arr[0];
    int painters = 2;
    int start = 40;
    int stop = 100;
    int result;
    while (start < stop)
    {
        int mid = (start + stop) / 2;
        int p = is_possible(arr, n, mid);
        if (p <= painters)
        {
            stop = mid;
        }
        else
        {
            start = mid;
        }
    }
    cout << start << endl;

    return 0;
}