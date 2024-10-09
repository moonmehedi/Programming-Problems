/*
This program is an implementation of two methods to check whether a binary tree is height-balanced or not.

The height-balanced tree is defined as a binary tree in which the left and right subtrees of every node differ in height by at most one.

The first method is height_balance_tree() which uses recursion to check whether a binary tree is height-balanced or not. It first checks if the root is NULL, and if it is, then it returns true because a NULL tree is always height-balanced. If the root is not NULL, it recursively checks if the left and right subtrees are height-balanced or not. If both the subtrees are height-balanced, then it calculates the height of both the subtrees and checks if their difference is at most one. If the difference is at most one, then the tree is height-balanced, and it returns true; otherwise, it returns false.

The second method is optimized_height_balance_tree() which is an optimized version of the first method. Instead of calculating the height of each subtree separately, it calculates the height of the left and right subtrees simultaneously. It does this by passing the pointers to the left_height and right_height variables to the recursive function and setting their values in the function itself. This way, it avoids calculating the height of each subtree separately, and it reduces the time complexity to O(n).

In the optimized_height_balance_tree() function, it checks if the root is NULL, and if it is, then it returns true because a NULL tree is always height-balanced. If the root is not NULL, it recursively checks if the left and right subtrees are height-balanced or not. If both the subtrees are height-balanced, then it calculates the height of both the subtrees and checks if their difference is at most one. If the difference is at most one, then it sets the height of the current node as the maximum height of its left and right subtrees plus one and returns true; otherwise, it returns false.

In the main() function, two binary trees are created, and the height_balance_tree() and optimized_height_balance_tree() functions are called for each tree to check whether they are height-balanced or not. The first tree is height-balanced, and both the functions return true for it. The second tree is not height-balanced, and both the functions return false for it.
*/

#include <bits/stdc++.h>
using namespace std;

// Define a class to represent each node of the binary tree
class node {
public:
    int data;
    node *left;
    node *right;

    // Constructor to initialize the node with a value
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function to check if a binary tree is height-balanced or not
// This function takes the root node of the binary tree and a pointer to an integer to store the height of the tree
bool optimized_height_balance_tree(node *root, int *height) {
    // If the root is NULL, then the height of the tree is 0 and the tree is balanced
    if (root == NULL) {
        *height = 0;
        return true;
    }

    // Variables to store the height of the left and right subtrees
    int left_height = 0, right_height = 0;

    // Check if the left subtree is balanced and calculate its height
    if (optimized_height_balance_tree(root->left, &left_height) == false) {
        return false;
    }

    // Check if the right subtree is balanced and calculate its height
    if (optimized_height_balance_tree(root->right, &right_height) == false) {
        return false;
    }

    // Calculate the height of the current node by adding 1 to the maximum of the heights of the left and right subtrees
    *height = max(left_height, right_height) + 1;

    // Check if the difference between the heights of the left and right subtrees is less than or equal to 1
    // If yes, then the tree is balanced
    if (abs(left_height - right_height) <= 1) {
        return true;
    }
    else {
        return false;
    }
}

// Helper function to calculate the height of a binary tree
// This function takes the root node of the binary tree
int height(node *root) {
    // If the root is NULL, then the height of the tree is 0
    if (root == NULL) {
        return 0;
    }

    // Calculate the height of the left subtree and the right subtree recursively
    // The height of a node is the maximum of the heights of its left and right subtrees, plus 1
    return max(height(root->left), height(root->right)) + 1;
}

// Function to check if a binary tree is height-balanced or not
// This function takes the root node of the binary tree
bool height_balance_tree(node *root) {
    // If the root is NULL, then the tree is balanced
    if (root == NULL) {
        return true;
    }

    // Check if the left subtree is balanced
    if (height_balance_tree(root->left) == false) {
        return false;
    }

    // Check if the right subtree is balanced
    if (height_balance_tree(root->right) == false) {
        return false;
    }

    // Calculate the height of the left subtree and the right subtree
    int left_height = height(root->left);
    int right_height = height(root->right);

    // Check if the difference between the heights of the left and right subtrees is less than or equal to 1
    // If yes, then the tree is balanced
    if (abs(left_height - right_height) <= 1) {
        return true;
    }
    else {
        return false;
    }
}

// Main function to test the height-balanced binary tree algorithms
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    if (height_balance_tree(root))
    {
        cout << "tree is balanced" << endl;
    }
    else
        cout << "tree is not balanced " << endl;

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(5);
    root2->right->right = new node(6);
    root2->right->right->left = new node(9);

    if (height_balance_tree(root2))
    {
        cout << "tree is balanced" << endl;
    }
    else
        cout << "tree is not balanced " << endl;

    cout << "calling for optimized" << endl;

    int height = 0;
    if (optimized_height_balance_tree(root, &height))
    {
        cout << "tree is balanced" << endl;
    }
    else
        cout << "tree is not balanced " << endl;
    // not balanced
    if (optimized_height_balance_tree(root2, &height))
    {
        cout << "tree is balanced" << endl;
    }
    else
        cout << "tree is not balanced " << endl;
}