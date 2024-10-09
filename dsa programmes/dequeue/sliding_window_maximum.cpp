#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
void sliding_window_maximum(int arr[], int size, int k)
{
    deque<int> dq(k);
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() and arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    for (int i = k; i < size; i++)
    {
        cout << arr[dq.front()] << endl;

        while (!dq.empty() and dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() and arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }
    cout << arr[dq.front()] << endl;
}

signed main()
{
    fast_io(); // enable faster I/O
    int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    sliding_window_maximum(arr, 9, 3);

    return 0;
}