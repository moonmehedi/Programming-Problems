#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int i;
        int count = 1;
        for (i = 1; i <= n; i++, count++)
        {
            if (arr[i] == count)
                count++;
        }
        cout << count - 1 << endl;
        t--;
    }
}