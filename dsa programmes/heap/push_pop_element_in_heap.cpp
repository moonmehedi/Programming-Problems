/*
Certainly! Here's an explanation of the code in simpler terms:

The code defines two functions: insert_at_heap and pop_from_heap.

The insert_at_heap function is used to insert an element into a heap. It takes a vector v and an integer key as input.

In the insert_at_heap function, the new element is appended to the end of the vector v. Then, a process called "heapify" is performed to maintain the heap property.

Heapify starts at the index of the new element and compares it with its parent. If the new element is greater than its parent, they are swapped. This process continues until the new element is no longer greater than its parent or until it reaches the root of the heap.

The pop_from_heap function is used to remove the maximum element from the heap. It takes a vector v as input.

In the pop_from_heap function, the maximum element (located at the root) is replaced with the last element in the vector.

After replacing the root, a process called "heapify" is performed again to maintain the heap property. Starting from the root, the element is compared with its children. If the element is smaller than any of its children, it is swapped with the larger child. This process continues until the element is no longer smaller than its children or until it reaches a leaf node.

Finally, the code demonstrates the usage of these functions. It initializes a vector v with some values, inserts a new element (30) into the heap using insert_at_heap, and then removes the maximum element from the heap using pop_from_heap.

The code prints the elements of the heap before and after the popping operation.

The goal of the code is to showcase how to insert elements into a heap and how to remove the maximum element from the heap while maintaining the heap property.


*/

#include <bits/stdc++.h>
using namespace std;

// Function to insert an element into the heap
void insert_at_heap(vector<int> &v, int key)
{
    v.push_back(key); // Add the new element to the end of the vector
    int n = v.size();

    int i = n - 1;
    while (i > 0)
    {
        // Compare the new element with its parent and swap if it is greater
        if (v[i] > v[(i - 1) / 2])
        {
            swap(v[i], v[(i - 1) / 2]);
            i = (i - 1) / 2; // Update the index to the parent's index
        }
        else
            break; // If the new element is not greater than its parent, stop the loop
    }
}

// Function to remove the maximum element from the heap
void pop_from_heap(vector<int> &v)
{
    int n = v.size();

    // Replace the root element with the last element
    v[0] = v[n - 1];
    int i = 0;

    while (i < n)
    {
        // Compare the root element with its children
        // and swap with the larger child if it is greater than the root
        if (v[2 * i + 1] > v[2 * i + 2] && v[2 * i + 1] > v[i])
        {
            swap(v[2 * i + 1], v[i]);
            i = 2 * i + 1; // Update the index to the left child's index
        }
        else if (v[2 * i + 1] < v[2 * i + 2] && v[2 * i + 2] > v[i])
        {
            swap(v[2 * i + 2], v[i]);
            i = 2 * i + 2; // Update the index to the right child's index
        }
        else
            break; // If the root element is not smaller than its children, stop the loop
    }
    v.pop_back(); // Remove the last element from the vector
}

int main()
{
    vector<int> v = {20, 12, 10, 9, 8, 7, 5, 2};

    insert_at_heap(v, 30); // Insert the element 30 into the heap

    for (auto i : v)
        cout << i << " ";

    pop_from_heap(v); // Remove the maximum element from the heap

    cout << endl
         << "After popping: " << endl;
    for (auto i : v)
        cout << i << " ";

    return 0;
}