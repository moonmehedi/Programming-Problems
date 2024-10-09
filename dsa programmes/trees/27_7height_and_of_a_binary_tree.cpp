
#include <bits/stdc++.h> // standard C++ library header file
using namespace std;

class node // defining a class named "node"
{
public:          // public access specifier
    int data;    // data stored in the node
    node *left;  // pointer to the left child of the node
    node *right; // pointer to the right child of the node

    node(int val) // constructor to initialize data, left, and right pointers
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height_of_a_binary_tree(node *root) // function to find the height of a binary tree
{
    if (root == NULL) // base case: if root is NULL, height is 0
        return 0;
    return max(height_of_a_binary_tree(root->left), height_of_a_binary_tree(root->right)) + 1; // recursive call to find the height of the left and right subtrees and return the maximum height plus 1 (for the root)
}

int main() // main function
{
    node *root = new node(1); // create a binary tree with root node as 1
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << height_of_a_binary_tree(root); // call the height_of_a_binary_tree function and print the result
}
