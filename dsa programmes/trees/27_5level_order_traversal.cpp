/*
This code is an implementation of level order traversal of a binary tree. Here is a more detailed explanation of the code:

The node class is defined to represent a node of the binary tree. Each node has a data value, a pointer to its left child, and a pointer to its right child.

The level_order_traversal function takes a pointer to the root node of the binary tree and performs the level order traversal.

The function uses a queue to keep track of the nodes to be visited. We start by pushing the root node into the queue, followed by a NULL node to mark the end of the first level.

We then enter a loop that runs until the queue becomes empty. In each iteration of the loop, we dequeue a node from the front of the queue and print its data value. We then check if the dequeued node has any children, and if so, we enqueue them into the queue.

If the dequeued node is a NULL node, we know that we have completed the traversal of one level of the binary tree. So we enqueue another NULL node to mark the end of the next level.

The main function creates a binary tree and calls the level_order_traversal function to perform the level order traversal of the tree.

The NULL nodes are used as delimiters to separate levels in the tree. When a NULL node is encountered, it means that the current level has been completely visited and we need to move to the next level. We keep pushing NULL nodes to the queue to indicate the end of the current level and the start of the next level until the queue is empty, which means that all levels have been visited.

*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
    Level Order Traversal using a queue:
    - We add the root node to the queue
    - We add a NULL character to the queue to represent the end of the first level
    - While the queue is not empty, we remove the front element from the queue
    - If the removed element is not NULL, we print its data and add its left and right children to the queue
    - If the removed element is NULL, we add another NULL character to represent the end of the current level
    - We continue this process until the queue is empty
*/
void level_order_traversal(node *root)
{
    queue<node *> q;
    q.push(root); // Add root node to queue
    q.push(NULL); // Add NULL character to represent end of first level

    while (!q.empty())
    {
        node *current = q.front(); // Get front element from queue
        q.pop();                   // Remove front element from queue

        if (current != NULL)
        {
            // If the current element is not NULL, print its data and add its left and right children to the queue
            cout << current->data << " ";
            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }
        else if (!q.empty())
        {
            // If the current element is NULL but the queue is not empty, add another NULL character to represent end of current level
            q.push(NULL);
        }
    }
    // If the queue is empty, all the levels have been visited
}

int main()
{
    // Create binary tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Traverse the tree using level order traversal
    level_order_traversal(root);
}