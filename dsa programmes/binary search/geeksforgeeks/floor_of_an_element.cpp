#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// function to find the index of the largest element in the vector that is less than or equal to x
int findFloor(vector<long long> v, long long n, long long x)
{
    if (v[n - 1] < x)
    {
        // if all elements are smaller than x, return the index of the last element
        return n - 1;
    }
    else if (v[0] > x)
    {
        // if all elements are greater than x, return -1
        return -1;
    }
    else
    {
        // use lower_bound to find the first element >= x
        vector<long long>::iterator ad = lower_bound(v.begin(), v.end(), x);
        if (*ad == x)
            // if we found x in the vector, return its index
            // it means x is present in array and floor of x is x
            return ad - v.begin();
        else
            // otherwise, return the index of the element before it
            // x not present iterator pointing to address greater than x return it's previous index that is slightly lower than x
            return ad - 1 - v.begin();
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
    int x;
    cin >> x;
    cout << findFloor(v, n, x);

    return 0;
}