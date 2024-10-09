#include <bits/stdc++.h>
using namespace std;

// Define a Queue class that uses two stacks to implement a queue
class Queue
{
    stack<int> instack;  // stack used for enqueuing elements
    stack<int> outstack; // stack used for dequeuing elements

public:
    // Method to add an element to the end of the queue
    void enqueue(int val)
    {
        instack.push(val);
    }
    // Method to remove and return the front element of the queue
    int dequeue()
    {
        // If the outstack is empty, transfer all elements from instack to outstack
        if (outstack.empty())
        {
            while (!instack.empty())
            {
                outstack.push(instack.top()); // Move the top element of instack to the top of outstack
                instack.pop();                // Remove the top element from instack
            }
        }
        // If the outstack is still empty, the queue is empty
        if (outstack.empty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        // Remove and return the front element of the queue
        int front = outstack.top(); // Get the top element of outstack (which is the front of the queue)
        outstack.pop();             // Remove the top element from outstack
        return front;               // Return the front element of the queue
    }
    // Method to check if the queue is empty
    bool empty()
    {
        return instack.empty() and outstack.empty();
    }
};

// Main function to test the Queue class
int main()
{
    Queue moon;      // Create a queue object
    moon.enqueue(1); // Add some elements to the queue
    moon.enqueue(2);
    moon.enqueue(3);
    cout << moon.dequeue() << endl; // Remove and print the front element of the queue
    cout << moon.dequeue() << endl; // Remove and print the front element of the queue
    cout << moon.dequeue() << endl; // Remove and print the front element of the queue
    cout << moon.dequeue() << endl; // Try to remove an element from an empty queue
    cout << moon.empty();           // Check if the queue is empty
    return 0;
}

/*
Sure, here's an explanation of the code:

First, we define a Queue class that uses two stacks to implement the queue data structure. The instack stack is used to enqueue elements, and the outstack stack is used to dequeue elements.

In the enqueue function, we simply push the given element val onto the instack.

In the dequeue function, we first check if the outstack is empty. If it is, we transfer all the elements from the instack to the outstack, reversing their order. We do this by repeatedly popping elements from the instack and pushing them onto the outstack.

Once we have ensured that the outstack is not empty, we return the top element of the outstack, which is the oldest element in the queue. We then pop this element from the outstack, removing it from the queue.

If both instack and outstack are empty, we print an error message and return -1.

The empty function returns true if both instack and outstack are empty, indicating that the queue is empty.

In the main function, we create an instance of the Queue class called moon. We then enqueue three elements 1, 2, and 3 into the queue using the enqueue function, and then dequeue all three elements using the dequeue function.

Finally, we call the empty function to check if the queue is empty, and print the result (which should be true)


*/
