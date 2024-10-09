#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// function overloading

float add(float a, float b)
{
    return a - b;
}
int add(char a, int b)
{
    return a + b;
}

signed main()
{
    fast_io(); // enable faster I/O
    // this is valid because here prototype is different;
    /*prototype different
    1//number of arguments are different
    2//parameter type
    3//return type
    */
    cout << add(5, 3) << endl;
    // cout << add(2, 3) << endl;

    return 0;
}