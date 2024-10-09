#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

class Queue
{
    int *arr;
    int front;
    int rear;
    int count;
    int size;

    Queue(int k)
    {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
        count = 0;
    }
    bool enqueue(int data)
    {
        if (isfull())
        {
            return false;
        }
        if (isempty())
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        arr[rear] = data;
        count++;
        return true;
    }

    bool dequeue()
    {
        if (isempty())
        {
            return false;
        }
        front = (front + 1) % size;
    }
};

signed
main()
{
    fast_io(); // enable faster I/O

    return 0;
}