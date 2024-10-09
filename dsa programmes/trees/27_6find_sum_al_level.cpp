/*
This is a C++ program that calculates the sum of nodes at a given level k of a binary tree using level order traversal. Here's how it works:

We start by creating a node class that defines the properties of a binary tree node. Each node has an integer value (data), and pointers to its left and right children (left and right, respectively).

We define the find_sum_of_node_at_k function that takes in a binary tree root and an integer k, and returns the sum of all nodes at level k.

We create a queue q to store the nodes of the binary tree.

We initialize level to 0 and sum to 0.

We use a while loop to traverse the binary tree using level order traversal.

Inside the while loop, we first get the number of nodes at the current level by getting the size of the queue q.

We use a for loop to process all nodes at the current level.

We dequeue a node val from the front of the queue q, and if the current level is equal to the given level k, we add its value to the sum.

We enqueue the left and right children of the current node val if they are not NULL.

After processing all nodes at the current level, we increment the level level by 1.

Finally, we return the sum of nodes at the given level k.

In the main function, we create a binary tree with 7 nodes and call the find_sum_of_node_at_k function with the root and level 2. The function returns the sum of all nodes at level 2, which is 11.

*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize node
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int find_sum_of_node_at_k(node *root, int k)
{
    queue<node *> q;
    q.push(root);  // push the root node into the queue
    int level = 0; // initialize the level to 0
    int sum = 0;   // initialize the sum to 0

    // BFS traversal
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *val = q.front(); // get the front element of the queue
            q.pop();               // remove the front element
            if (level == k)
            {                     // if current level is equal to k
                sum += val->data; // add the value of the node to the sum
            }
            if (val->left != NULL)
            { // if left child exists, push it into the queue
                q.push(val->left);
            }
            if (val->right)
            { // if right child exists, push it into the queue
                q.push(val->right);
            }
        }
        level++; // increment the level
    }

    return sum; // return the sum
}

int main()
{
    // create the binary tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // call the function to find the sum of nodes at level k
    cout << find_sum_of_node_at_k(root, 2);

    return 0;
}