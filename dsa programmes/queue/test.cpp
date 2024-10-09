#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
class node
{
public:
    int data;
    node *next;

public:
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
    node *front;
    node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }
    // operation
    void enqueue(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            cout << "empty" << endl;
            return false;
        }
        return true;
    }
};

signed
main()
{
    fast_io(); // enable faster I/O
    Queue moon;
    moon.enqueue(1);
    moon.enqueue(2);
    moon.enqueue(3);
    cout << moon.peek() << endl;
    moon.dequeue();
    cout << moon.peek() << endl;
    moon.dequeue();
    cout << moon.peek() << endl;
    moon.dequeue();

    return 0;
}