#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void insert(int x)
{
    if (max_heap.size() == 0)
    {
        max_heap.push(x);
        return;
    }

    else if (max_heap.size() == min_heap.size())
    {
        if (x < max_heap.top())
        {
            max_heap.push(x);
        }
        else
            min_heap.push(x);
    }

    else if (max_heap.size() > min_heap.size())
    {
        if (x >= max_heap.top())
        {
            min_heap.push(x);
        }
        else{
            min_heap.push(max_heap.top());
            max_heap.pop();
            max_heap.push(x);}
    }

    else if (max_heap.size() < min_heap.size())
    {
        if (x <= max_heap.top())
        {
            max_heap.push(x);
        }
        else
           { max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(x);}
    }
}

float findmedium()
{
    if (max_heap.size() == min_heap.size())
    {
        return (max_heap.top() + min_heap.top()) / 2.0;
    }
    else if (max_heap.size() > min_heap.size())
    {
        return max_heap.top();
    }
    else
    {
        return min_heap.top();
    }
}

int main()
{
    insert(10);
    cout << findmedium() << endl;
    insert(15);
    cout << findmedium() << endl;
    insert(21);
    cout << findmedium() << endl;
    insert(30);
    cout << findmedium() << endl;
    insert(18);
    cout << findmedium() << endl;
    insert(19);
    cout << findmedium() << endl;
}