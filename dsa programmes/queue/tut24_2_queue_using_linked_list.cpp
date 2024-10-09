#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define size 10
#define endl '\n'

// Define a class for a node of a linked list
class node
{
public:
    int data;   // Data stored in the node
    node *next; // Pointer to the next node in the linked list

    // Constructor to create a new node with the given integer value
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Define a class for a queue data structure
class Queue
{
public:
    node *front; // Pointer to the front (first) node of the queue
    node *back;  // Pointer to the back (last) node of the queue

    // Constructor to create an empty queue with front and back pointers set to NULL
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    // Add an integer value to the back of the queue
    void push(int val)
    {
        node *n = new node(val); // Create a new node with the given integer value
        if (front == NULL)       // If the queue is empty
        {
            back = n; // Set both front and back pointers to the new node
            front = n;
        }
        else // If the queue is not empty
        {
            back->next = n; // Set the next pointer of the current back node to the new node
            back = n;       // Set the back pointer to the new node
        }
    }

    // Remove the front element of the queue
    void pop()
    {
        if (front == NULL) // If the queue is empty
        {
            cout << "Queue under flow ";
        }
        else // If the queue is not empty
        {
            node *todelete = front; // Store the current front node in a temporary pointer
            front = front->next;    // Move the front pointer to the next node
            delete todelete;        // Delete the previous front node
        }
    }

    // Return the data value of the front element of the queue
    int peek()
    {
        if (front == NULL) // If the queue is empty
        {
            cout << "No Element In Queue " << endl;
        }
        return front->data; // Return the data value of the front node
    }

    // Check if the queue is empty
    bool empty()
    {
        if (front == NULL) // If the front pointer is NULL, the queue is empty
            return true;
        return false;
    }
};

// Main function
signed main()
{
    fast_io(); // Enable faster I/O by turning off the synchronization of C++ streams with C standard streams and disabling buffering of cin and cout

    Queue moon;                 // Create an object of the Queue class
    for (int i = 0; i < 5; i++) // Push five integers into the queue
    {
        moon.push(i + 1);
    }

    // Print and remove all the elements of the queue using peek() and pop() functions
    for (; moon.front != NULL;)
    {
        cout << moon.peek() << endl;
        moon.pop();
    }

    cout << moon.empty(); // Check if the queue is empty using the empty()
}

/*
This code is an implementation of Queue data structure using Linked List in C++. The code uses the following classes and functions:

Class node: This class defines a node which contains a data value and a pointer to the next node.

Class Queue: This class defines a queue data structure using a linked list. It contains two pointers, 'front' and 'back', which point to the first and last nodes of the queue, respectively. The class has the following member functions:

push(): This function takes an integer as input and adds it to the back of the queue by creating a new node with the given integer value and pointing the current back node's next pointer to it. If the queue is empty, the front pointer is also set to the new node.

pop(): This function removes the front element of the queue by moving the front pointer to the next node and deleting the previous front node. If the queue is empty, it prints "Queue under flow".

peek(): This function returns the data value of the front element of the queue. If the queue is empty, it prints "No Element In Queue".

empty(): This function returns a boolean value indicating whether the queue is empty or not.

The code defines two macros:

fast_io(): This macro is used to enable faster I/O by turning off the synchronization of C++ streams with C standard streams and disabling buffering of cin and cout.

int long long: This macro defines the 'int' data type as a 'long long' data type.

The code defines a main function which creates an object of the Queue class, pushes five integers into the queue, and then pops and prints all the elements of the queue using the peek() and pop() functions. Finally, it checks if the queue is empty using the empty() function and prints the result
*/