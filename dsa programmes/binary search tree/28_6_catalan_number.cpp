#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

int catalan(int n)
{
    // if reach the base retunr 1
    if (n == 1 or n == 0)
    {
        return 1;
    }
    int res = 0;

    // this loop summation catalan number from 0 to n-1
    for (int i = 0; i <= n - 1; i++)
    {
        // this recursion call find every value of catalan numbe and
        // summet it in result
        res += catalan(i) * catalan(n - i - 1);
    }
    // return nth catalan  number
    return res;
}
signed main()
{
    fast_io(); // enable faster I/O
    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << endl;
    }

    return 0;
}