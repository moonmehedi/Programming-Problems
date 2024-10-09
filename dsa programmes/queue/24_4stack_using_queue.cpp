#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

class Stack
{
    int n;
    queue<int> q1; // main queue
    queue<int> q2; // temporary queue

public:
    Stack()
    {
        n = 0;
    }

    // push operation: adding a new element to the top of the stack
    void push(int val)
    {
        // add the new element to the temporary queue
        q2.push(val);

        // move all elements from the main queue to the temporary queue
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the main and temporary queues
        swap(q1, q2);

        // increment the size of the stack
        n++;
    }

    // pop operation: remove the top element from the stack
    void pop()
    {
        // if the stack is already empty, output an error message
        if (q1.empty())
        {
            cout << "stack is empty " << endl;
        }

        // remove the front element from the main queue
        q1.pop();

        // decrement the size of the stack
        n--;
    }

    // top operation: return the top element of the stack
    int top()
    {
        // if the stack is already empty, output an error message
        if (q1.empty())
        {
            cout << "stack is empty " << endl;
        }

        // return the front element of the main queue
        return q1.front();
    }

    // size operation: return the size of the stack
    int size()
    {
        return n;
    }
};

signed main()
{
    fast_io(); // enable faster I/O

    Stack moon;

    // push some elements to the stack
    moon.push(1);
    moon.push(2);
    moon.push(3);

    // output the size of the stack
    cout << "size of stack " << moon.size() << endl;

    // output the top element of the stack
    cout << moon.top() << endl;

    // pop some elements from the stack
    moon.pop();
    cout << moon.top() << endl;
    moon.pop();
    cout << moon.top() << endl;
    moon.pop();

    return 0;
}

/*
This code implements a stack data structure using two queues in C++.

The Stack class has two private queues q1 and q2. The push() method adds an element to the stack by first adding the new element to the q2 queue, then transferring all elements from q1 to q2 and finally assigning q2 to q1 to maintain the order of elements. The pop() method removes the top element from q1. The top() method returns the top element of the stack, which is the front element of the q1 queue.

In the main() function, the code creates an instance of the Stack class, adds three elements (1, 2, and 3) to the stack using the push() method, prints the top element of the stack using the top() method, and removes the top element of the stack twice using the pop() method. Finally, the code returns 0.
*/