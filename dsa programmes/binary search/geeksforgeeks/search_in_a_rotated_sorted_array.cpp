#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int search(int A[], int l, int h, int key)
{
    int n = h + 1;
    int mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (A[mid] < A[mid - 1])
        {
            break;
        }
        else if (A[mid] >= A[0])
        {
            l = mid + 1;
        }
        else if (A[mid] < A[0])
        {
            h = mid - 1;
        }
    }
    int a;
    int *ad;
    if (key >= A[0])
    {
        ad = lower_bound(A, A + mid, key);

        a = distance(A, ad);
    }
    else if (key < A[0])
    {
        ad = lower_bound(A + mid, A + n, key);
        a = distance(A, ad);
    }
    if (ad != A + n and *ad == key)
    {
        return a;
    }
    else
        return -1;
}

signed main()
{
    fast_io(); // enable faster I/O
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << search(arr, 0, n - 1, key);

    return 0;
}