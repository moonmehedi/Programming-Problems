/*
The given code defines a binary tree and provides two functions to count the total number of nodes in the tree and the sum of values of all nodes in the tree.

Here's a brief explanation of the code:

A node class is defined with data members data, left, and right. It has a constructor that takes an integer val and initializes data to val and left and right pointers to NULL.

The function count_all_nodes takes a root pointer and returns the total number of nodes in the tree with root as the root node. If root is NULL, then the function returns 0, otherwise, it recursively calculates the number of nodes in the left subtree, right subtree, and adds 1 for the root node.

The function count_value_of_all_nodes takes a root pointer and returns the sum of values of all nodes in the tree with root as the root node. If root is NULL, then the function returns 0, otherwise, it recursively calculates the sum of values of nodes in the left subtree, right subtree, and adds the value of the root node.

In the main function, a binary tree is created with 7 nodes, and the functions count_all_nodes and count_value_of_all_nodes are called with the root of the tree as an argument. The results are printed to the console.

It's worth noting that this implementation assumes that the values of all nodes are positive integers. If there are negative integers or other types of data, modifications to the implementation may be needed.

*/

#include <bits/stdc++.h>
using namespace std;

// Define a node class for binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize a node with given data
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to count all nodes in the tree
int count_all_nodes(node *root)
{
    // Base case: if root is NULL, return 0
    if (root == NULL)
        return 0;

    // Recursively count nodes in left and right subtrees
    return count_all_nodes(root->left) + count_all_nodes(root->right) + 1;
}

// Recursive function to calculate the sum of all node values in the tree
int count_value_of_all_nodes(node *root)
{
    // Base case: if root is NULL, return 0
    if (root == NULL)
        return 0;

    // Recursively calculate sum of node values in left and right subtrees
    return count_value_of_all_nodes(root->left) + count_value_of_all_nodes(root->right) + root->data;
}

int main()
{
    // Create a binary tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Call count_all_nodes() function and print the result
    cout << count_all_nodes(root) << endl;

    // Call count_value_of_all_nodes() function and print the result
    cout << count_value_of_all_nodes(root);
}