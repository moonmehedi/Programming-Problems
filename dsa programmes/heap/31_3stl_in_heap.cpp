#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int, vector<int>> max_heap;
    max_heap.push(1);
    max_heap.push(2);
    max_heap.push(3);
    max_heap.push(4);

    cout << max_heap.top() << endl;
    max_heap.pop();
    cout << max_heap.top() << endl;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(1);
    min_heap.push(2);
    min_heap.push(3);
    min_heap.push(4);

    cout << min_heap.top() << endl;
    min_heap.pop();
    cout << min_heap.top() << endl;
}