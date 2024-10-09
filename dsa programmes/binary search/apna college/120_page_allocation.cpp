#include <bits/stdc++.h>
using namespace std;

bool is_fisible(int arr[], int n, int m, int pages)
{
    int s = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        // if (arr[i] > pages)
        // {
        //     return false;
        // }
        sum = sum + arr[i];
        if (sum > pages)
        {
            s++;
            sum = arr[i];
        }
    }
    if (s == m)
    {
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int first = 0, last = 500;
    int result = INT_MAX;
    int student = 2;

    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (is_fisible(arr, n, student, mid))
        {

            result = min(result, mid);
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }

    cout << result;
}