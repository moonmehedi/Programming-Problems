/*
This algorithm performs sum replacement in a binary tree, i.e., for each node, it replaces the value of the node with the sum of its own value and the values of its left and right child nodes, if they exist.

The algorithm takes a binary tree as input and recursively traverses the tree in a postorder manner. For each node, it first calls the sum_replacement() function for its left child and right child nodes, respectively. If either of the calls returns a non-null value, it adds the value of that child node to the current node's data. Finally, the function returns the updated node.

After performing sum replacement, the preorder() function is called to print the updated binary tree in pre-order traversal. The output will show the new values of each node after sum replacement has been performed.
*/

#include <bits/stdc++.h>
using namespace std;

// node structure for binary tree
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor to initialize a new node
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// function to perform sum replacement in binary tree
node *sum_replacement(node *root)
{
    // if root is NULL, return NULL
    if (root == NULL)
        return NULL;

    // recursively call sum_replacement function for left subtree
    if (sum_replacement(root->left) != NULL)
    {
        root->data += root->left->data;
    }

    // recursively call sum_replacement function for right subtree
    if (sum_replacement(root->right) != NULL)
    {
        root->data += root->right->data;
    }

    // return the updated root node
    return root;
}

// function to perform preorder traversal of binary tree
void preorder(node *root)
{
    // base case: if root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // print the current node's data
    cout << root->data << " ";

    // recursively call preorder function for left subtree
    preorder(root->left);

    // recursively call preorder function for right subtree
    preorder(root->right);
}

int main()
{
    // create a binary tree
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // perform sum replacement in binary tree
    sum_replacement(root);

    // perform preorder traversal of binary tree and print the updated data of each node
    preorder(root);
}