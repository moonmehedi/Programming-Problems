#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

void heapify(vector<int> &v, int i, int n)
{
    int parent = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < n and v[left_child] > v[parent])
    {
        swap(v[parent], v[left_child]);
        parent = left_child;
    }
    else if (left_child < n and v[left_child] > v[parent])
    {
        swap(v[parent], v[left_child]);
        parent = left_child;
    }
}

void heapsort(vector<int> &v)
{
    int n = v.size() - 1;
    int last_parent = (n - 1) / 2;

    for (int i = last_parent; i > 0; i--)
    {
        heapify(v, i, n);
    }
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> v = {10, 15, 21, 30, 18, 19};

    heapsort(v);

    return 0;
}