#include <bits/stdc++.h>
using namespace std;
bool convert_binary(int a)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            if (i == a / i)
            {
                sum += i;
            }
            else
                sum += i + (a / i);
        }
    }
    return sum == a;
}

int main()
{

    int arr[] = {6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    bool binaryarr[n];
    for (int i = 0; i < n; i++)
    {
        binaryarr[i] = convert_binary(arr[i]);
    }

    int maxlen = 0;
    int start = 0;
    // int stop = 0;

    for (int stop = 0; stop < n;)
    {

        if (binaryarr[stop] == false)
        {
            stop++;
        }
        else if (binaryarr[stop] == true)
        {
            start = stop;
            // stop = stop;
            while (binaryarr[stop] != false and stop < n)
            {
                stop++;
            }
            maxlen = max(maxlen, stop - start);
        }
    }
    cout << maxlen;
}