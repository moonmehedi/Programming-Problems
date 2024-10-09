#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
bool is_feasible(int distance, int arr[], int n, int k)
{
    int first = 0;
    int last = n - 1;
    int point = distance + arr[0];
    int count = 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] >= point)
        {
            first = mid + 1;
            last = n - 1;
            point = point + distance;
            count++;
            if (k == count)
            {
                return true;
            }
        }
        else if (arr[mid] < point)
        {
            first = mid + 1;
        }
        else if (arr[mid] > point)
        {
            last = mid - 1;
        }
    }
    return false;
}

signed main()
{
    fast_io(); // enable faster I/O

    int arr[] = {5, 7, 11, 12, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> result;
    sort(arr, arr + n);
    int k = 3;
    // check feasibility
    int left = 0;
    int right = arr[n - 1];

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (is_feasible(mid, arr, n, k))
        {
            result.clear();
            result.push_back(mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}