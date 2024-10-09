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

// Preorder traversal of a binary tree
void preorder(node *root)
{
    // If the root is NULL, return immediately
    if (root == NULL)
    {
        return;
    }

    // Print the value of the root
    cout << root->data << " ";

    // Recursively traverse the left subtree
    preorder(root->left);

    // Recursively traverse the right subtree
    preorder(root->right);
}

// Inorder traversal of a binary tree
void inorder(node *root)
{
    // If the root is NULL, return immediately
    if (root == NULL)
    {
        return;
    }

    // Recursively traverse the left subtree
    inorder(root->left);

    // Print the value of the root
    cout << root->data << " ";

    // Recursively traverse the right subtree
    inorder(root->right);
}

// Postorder traversal of a binary tree
void postorder(node *root)
{
    // If the root is NULL, return immediately
    if (root == NULL)
    {
        return;
    }

    // Recursively traverse the left subtree
    postorder(root->left);

    // Recursively traverse the right subtree
    postorder(root->right);

    // Print the value of the root
    cout << root->data << " ";
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

    // Perform a preorder traversal of the tree and print the nodes
    cout << "preoder traversal :" << endl;
    preorder(root);
    cout << endl;

    // Perform an inorder traversal of the tree and print the nodes
    cout << "inorder traversal : " << endl;
    inorder(root);
    cout << endl;

    // Perform a postorder traversal of the tree and print the nodes
    cout << "postorder traversal : " << endl;
    postorder(root);
}

/*
This is a C++ program that implements three types of traversals in a binary tree: preorder, inorder, and postorder. The program creates a binary tree using a class called node, which has a data member data to store the node's value, and two pointers, left and right, to point to the node's left and right children, respectively.

The preorder function traverses the binary tree in a preorder manner, which means it visits the current node, its left subtree, and then its right subtree. The function takes a pointer to the root of the tree as an argument, and if the pointer is NULL, it returns immediately. Otherwise, it prints the data of the current node, then recursively calls itself with the left subtree and the right subtree of the current node, respectively.

The inorder function traverses the binary tree in an inorder manner, which means it visits the left subtree of the current node, then the current node itself, and then the right subtree. The function takes a pointer to the root of the tree as an argument, and if the pointer is NULL, it returns immediately. Otherwise, it recursively calls itself with the left subtree of the current node, then prints the data of the current node, and finally recursively calls itself with the right subtree of the current node.

The postorder function traverses the binary tree in a postorder manner, which means it visits the left subtree of the current node, then the right subtree, and then the current node itself. The function takes a pointer to the root of the tree as an argument, and if the pointer is NULL, it returns immediately. Otherwise, it recursively calls itself with the left subtree of the current node, then recursively calls itself with the right subtree of the current node, and finally prints the data of the current node.

The main function creates a binary tree with seven nodes, and then calls the three traversal functions in sequence to print the nodes in preorder, inorder, and postorder.
*/