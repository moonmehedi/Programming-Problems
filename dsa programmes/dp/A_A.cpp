#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

int b_s(const vector<int>& arr, int target) {
    int start = 0;
    int stop = arr.size() - 1;
    int result = -1;
    while (start <= stop) {
        int mid = start + (stop - start) / 2;
        if (arr[mid] >= target) {
            result = mid;
            stop = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

signed main() {
    fast_io(); // enable faster I/O
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int store;
        cin >> store;
        int idx = b_s(arr, store);
        if (idx != -1 && arr[idx] == store) {
            cout << "Yes " << idx + 1 << endl;
        } else {
            cout << "No " << idx + 1 << endl;
        }
    }
    return 0;
}