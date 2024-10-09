#include <bits/stdc++.h> // include necessary header files
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
#define size 20

class Queue // define a Queue class
{
public:
    int *arr;  // array to store the elements of the queue
    int front; // front index of the queue
    int back;  // rear index of the queue

    Queue() // constructor of the class
    {
        arr = new int[20]; // dynamic memory allocation to the queue array
        front = -1;        // set front index to -1 initially
        back = -1;         // set rear index to -1 initially
    }

    void push(int x) // method to push an element into the queue
    {
        if (back == size - 1) // if the queue is full
        {
            cout << "QUEUE OVER FLOW" << endl; // print an error message
            return;                            // exit the function
        }

        back++;        // increment the rear index
        arr[back] = x; // add the new element at the rear end

        if (front == -1) // if the queue was empty before
            front++;     // set the front index to 0
    }

    void pop() // method to remove an element from the front of the queue
    {
        empty(); // check if the queue is empty
        front++; // increment the front index
    }

    int peek() // method to get the front element of the queue
    {
        empty();           // check if the queue is empty
        return arr[front]; // return the front element
    }

    bool empty() // method to check if the queue is empty or not
    {
        if (front == -1 or front > back) // if the front index is out of bounds or greater than the rear index
        {
            cout << "QUEUE is EMPTY" << endl; // print a message indicating that the queue is empty
            return true;                      // return true
        }
        return false; // otherwise return false
    }
};

signed main()
{
    fast_io();  // enable faster I/O
    Queue moon; // create an instance of the Queue class

    for (int i = 0; i < 5; i++) // loop to insert elements into the queue
    {
        moon.push(i + 1); // add the elements to the queue
    }

    for (; moon.front <= moon.back;) // loop to print the elements of the queue
    {
        cout << moon.peek() << endl; // print the front element of the queue
        moon.pop();                  // remove the front element from the queue
    }

    moon.empty(); // check if the queue is empty

    return 0; // end of the program
}

/*This code implements a queue data structure using a dynamic array in C++.

The Queue class has three data members - an integer pointer arr for the dynamic array, and two integers front and back to keep track of the front and back elements of the queue.

The constructor of the class initializes the front and back indices to -1, indicating an empty queue.

The push method adds an element to the back of the queue, by incrementing back and assigning the new element to arr[back]. If the back index reaches the maximum size of the array (which is defined as size), it prints an error message indicating that the queue has overflowed.

The pop method removes the front element of the queue, by incrementing front. It first calls the empty method to check if the queue is empty.

The peek method returns the value of the current front element of the queue. It also calls the empty method to check if the queue is empty before returning the front element.

The empty method returns a boolean value true if the queue is empty and false otherwise. It checks if the front index is equal to -1 (which indicates an empty queue), or if the front index has passed the back index (which indicates that the queue is empty after some elements have been removed).

In the main function, an instance of the Queue class named moon is created. Five integers are pushed to the queue using the push method, and then the elements are printed and removed using a for loop that continues as long as the front index is less than or equal to the back index. Finally, the empty method is called to check if the queue is empty
*/