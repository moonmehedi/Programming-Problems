/*
This program implements the functions to print the right and left view of a binary tree. The right view of a binary tree is the set of nodes visible when the tree is viewed from the right side, i.e., the rightmost node in each level. Similarly, the left view of a binary tree is the set of nodes visible when the tree is viewed from the left side, i.e., the leftmost node in each level.

The program uses a queue to traverse the binary tree level by level. For each level, it keeps track of the number of nodes in that level using the size variable. Then, it dequeues each node from the queue and enqueues its left and right child, if they exist. If the dequeued node is the last node in that level (i.e., i == size-1 for the right view or i == 0 for the left view), then its value is printed.

Here is a more detailed explanation of the functions:

void right_view_of_a_binary_tree(node *root): This function takes the root of a binary tree as input and prints the right view of the tree. It starts by enqueueing the root node into a queue. Then, it enters a loop that runs until the queue becomes empty. In each iteration of the loop, it dequeues each node from the queue and enqueues its left and right child, if they exist. If the dequeued node is the last node in that level (i.e., i == size-1), then its value is printed. This way, the function prints the rightmost node in each level.

void left_view_of_a_binary_tree(node *root): This function takes the root of a binary tree as input and prints the left view of the tree. It follows the same logic as the right_view_of_a_binary_tree function, with one difference: it prints the value of the first node in each level (i.e., i == 0). This way, the function prints the leftmost node in each level.

Finally, in the main function, a binary tree with seven nodes is created, and the right_view_of_a_binary_tree and left_view_of_a_binary_tree functions are called to print the respective views of the tree.
*/

#include <bits/stdc++.h>
using namespace std;

// Class for a binary tree node
class node
{
public:
    int data;    // Data stored in the node
    node *left;  // Pointer to the left child of the node
    node *right; // Pointer to the right child of the node

    // Constructor to initialize a node with the given value and null left and right pointers
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to print the right view of a binary tree
void right_view_of_a_binary_tree(node *root)
{
    // Create a queue to store the nodes of the binary tree
    queue<node *> q;

    // Enqueue the root node
    q.push(root);

    // Traverse the binary tree level by level
    while (!q.empty())
    {
        // Get the number of nodes in the current level
        int size = q.size();

        // Traverse all the nodes in the current level
        for (int i = 0; i < size; i++)
        {
            // Dequeue the front node from the queue
            node *val = q.front();
            q.pop();

            // If the node is the last node in the level, print its value
            if (i == size - 1)
            {
                cout << val->data << endl;
            }

            // Enqueue the left child of the current node, if it exists
            if (val->left != NULL)
            {
                q.push(val->left);
            }

            // Enqueue the right child of the current node, if it exists
            if (val->right != NULL)
            {
                q.push(val->right);
            }
        }
    }
}

// Function to print the left view of a binary tree
void left_view_of_a_binary_tree(node *root)
{
    // Create a queue to store the nodes of the binary tree
    queue<node *> q;

    // Enqueue the root node
    q.push(root);

    // Traverse the binary tree level by level
    while (!q.empty())
    {
        // Get the number of nodes in the current level
        int size = q.size();

        // Traverse all the nodes in the current level
        for (int i = 0; i < size; i++)
        {
            // Dequeue the front node from the queue
            node *val = q.front();
            q.pop();

            // If the node is the first node in the level, print its value
            if (i == 0)
            {
                cout << val->data << " " << endl;
            }

            // Enqueue the left child of the current node, if it exists
            if (val->left != NULL)
            {
                q.push(val->left);
            }

            // Enqueue the right child of the current node, if it exists
            if (val->right != NULL)
            {
                q.push(val->right);
            }
        }
    }
}

int main()
{
    // Create a binary tree with seven nodes
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Print the right view of the binary tree
    cout << "right view" << endl;
    right_view_of_a_binary_tree(root);
    cout<<"left view"<<endl;
    left_view_of_a_binary_tree(root);
}