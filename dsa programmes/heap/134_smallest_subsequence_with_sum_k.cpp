#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>> max_heap;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        max_heap.push(x);
    }

    int sum = 0, count = 0;
    while (!max_heap.empty())
    {
        sum = sum + max_heap.top();
        max_heap.pop();

        count++;
        if (k <= sum)
        {
            cout << count << endl;
            return 0;
        }
    }

    cout << "not possible" << endl;
}