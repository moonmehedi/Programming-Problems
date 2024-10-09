#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

// define a class for stack
class Stack
{
    int n; // variable to store size of stack
    queue<int> q1; // two queues to implement stack
    queue<int> q2;

public:
    // constructor to initialize variables
    Stack()
    {
        n = 0;
    }

    // function to add element to top of stack
    void push(int val)
    {
        q1.push(val); // add element to queue 1
        n++; // increment size of stack
    }

    // function to remove element from top of stack
    void pop()
    {
        if (q1.empty()) // if stack is empty
        {
            cout << "stack is empty " << endl; // print error message
            return;
        }

        // move all elements from queue 1 to queue 2 except last element
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop(); // remove last element from queue 1
        swap(q1,q2); // swapping q1 and q2
        n--; // decrement size of stack
    }

    // function to get element at top of stack
    int top()
    {
        if (q1.empty()) // if stack is empty
        {
            cout << "stack is empty " << endl; // print error message
            return -1; // return -1 as there is no top element
        }
        else
        {
            // move all elements from queue 1 to queue 2 except last element
            while (q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int ans = q1.front(); // get the last element from queue 1
            q2.push(q1.front()); // add last element to queue 2
            q1.pop(); // remove last element from queue 1
            swap(q1,q2); // swapping q1 and q2

            return ans; // return last element as top of stack
        }
    }

    // function to get size of stack
    int size()
    {
        return n;
    }
};

signed main()
{
    fast_io(); // enable faster I/O

    // create a stack object
    Stack moon;

    // add elements to stack
    moon.push(1);
    moon.push(2);
    moon.push(3);
    moon.push(4);

    // print size of stack
    cout << "size  " << moon.size() << endl;

    // print top element and remove it from stack
    cout << moon.top() << endl;
    moon.pop();

    // print top element and remove it from stack
    cout << moon.top() << endl;
    moon.pop();

    // print top element and remove it from stack
    cout << moon.top() << endl;
    moon.pop();

    // print size of stack
    cout << "size  " << moon.size() << endl;

    return 0;
}

/*
This is an implementation of a stack data structure using two queues in C++.

A stack is a data structure that operates based on a Last-In-First-Out (LIFO) principle. This means that the most recently added element is removed first. A queue, on the other hand, operates based on a First-In-First-Out (FIFO) principle, where the first element added is removed first.

To implement a stack using two queues, we can use one queue for push operation and the other queue for pop operation. The basic idea is to keep all the elements in one queue while performing the push operation. When a pop operation is needed, we move all but the last element to the second queue. Then we remove the last element from the first queue, which is the top element of the stack. Finally, we swap the two queues so that the first queue becomes the second queue and the second queue becomes the first queue.

Let's see how the code works:

We first define a class called Stack that contains two queues q1 and q2, and an integer n that keeps track of the number of elements in the stack.
We initialize n to 0 in the constructor of the Stack class.
We implement the push() function, which adds an element to the first queue q1 and increments n.
We implement the pop() function, which checks if q1 is empty. If it is empty, it prints an error message and returns. Otherwise, it moves all but the last element from q1 to q2. Then it removes the last element from q1, decrements n, and swaps the two queues.
We implement the top() function, which is similar to the pop() function except that it doesn't remove the last element from q1. Instead, it returns the last element as the top element of the stack.
We implement the size() function, which simply returns n.
Finally, in the main() function, we create a Stack object called moon and perform some push and pop operations on it to demonstrate how the stack works.
Overall, this implementation of a stack using two queues is a simple and efficient way to implement a stack data structure.

*/