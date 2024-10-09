#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
#define n 10

class Stack
{
public:
    int *arr;
    int top;
    Stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "STACK OVERFLOW " << endl;
            return;
        }
        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "STACK IS EMPTY " << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "STACK IS EMPTY " << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return (top == -1);
    }
};

signed
main()
{
    fast_io(); // enable faster I/O
    Stack moon;

    moon.push(1);
    moon.push(2);
    moon.push(3);
    moon.push(4);
    for (; moon.top != -1; moon.pop())
    {
        cout << moon.Top() << " ";
    }
    cout << endl;
    moon.Top();
    moon.pop();
    cout << moon.empty();

    return 0;
}