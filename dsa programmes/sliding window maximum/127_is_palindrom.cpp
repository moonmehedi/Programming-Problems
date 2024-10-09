#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

// #define int long long // define int as a long long data type
#define endl '\n'

bool palindrom(int sum)
{
    int temp = sum, number = 0;
    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp = temp / 10;
    }
    if (number == sum)
    {
        return true;
    }
    return false;
}

void print(vector<int> const &v, int start, int k)
{
    for (int i = start; i < start + k; i++)
    {
        cout << v[i] << " ";
    }
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int sum = 0, k = 4;

    for (int i = 0; i < k; i++)
    {
        sum = sum * 10 + arr[i];
    }
    if (palindrom(sum))
    {
        print(arr, 0, k);
        return 0;
    }

    for (int i = k; i < arr.size(); i++)
    {
        sum = (sum % int(pow(10, k - 1))) * 10 + arr[i];
        if (palindrom(sum))
        {
            print(arr, i - k + 1, k);
            return 0;
        }
    }
    cout << "no subarray containing palindrome number " << endl;

    return 0;
}