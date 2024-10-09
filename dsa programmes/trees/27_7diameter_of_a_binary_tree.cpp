/*
Diameter of a Binary Tree:
The diameter of a binary tree is defined as the length of the longest path between any two nodes in a tree. This path may or may not pass through the root node. To find the diameter of a binary tree, we can use a recursive approach where we calculate the height of the left and right subtree of the current node and add them together along with 1 (for the current node) to get the current diameter. We then recursively find the diameter of the left and right subtree and return the maximum value among the current diameter and both subtree diameters.

In the given program, the function height calculates the height of the tree using recursion, and the caldiameter function uses the above recursive approach to find the diameter of the binary tree.

The optimized version of the diameter function, optimized_diameter, does not calculate the height of the tree recursively every time. Instead, it uses a pointer to store the height of the left and right subtree and updates it every time it calculates the diameter of the left and right subtree. This way, the height of each subtree is calculated only once, which makes this algorithm more efficient than the previous one.
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

// function to calculate the height of the tree
int height(node *root)
{
    if (root == NULL)
        return 0;
    // recursively calculate the maximum height of the left and right subtree
    return max(height(root->left), height(root->right)) + 1;
}

// function to calculate the diameter of the tree
int caldiameter(node *root)
{
    if (root == NULL)
        return 0;
    // calculate the height of the left and right subtree
    int left_height = height(root->left);
    int right_height = height(root->right);

    // calculate the diameter passing through the current node
    int current_diameter = left_height + right_height + 1;

    // recursively calculate the diameter of the left and right subtree
    int left_diameter = caldiameter(root->left);
    int right_diameter = caldiameter(root->right);

    // return the maximum of the three diameters
    return max(current_diameter, max(left_diameter, right_diameter));
}

// function to calculate the diameter of the tree in an optimized way
int optimized_diameter(node *root, int *height)
{
    if (root == NULL)
    {
        // if the node is null, set the height to 0
        *height = 0;
        return 0;
    }
    int left_height, right_height;
    // recursively calculate the diameter and height of the left and right subtree
    int left_diameter = optimized_diameter(root->left, &left_height);
    int right_diameter = optimized_diameter(root->right, &right_height);

    // set the height of the current node to the maximum of the left and right subtree heights
    *height = max(left_height, right_height) + 1;

    // calculate the diameter passing through the current node
    int current_diameter = left_height + right_height + 1;

    // return the maximum of the three diameters
    return max(current_diameter, max(left_diameter, right_diameter));
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // calculate the diameter of the tree using the height function
    cout << caldiameter(root) << endl;

    // calculate the diameter of the tree in an optimized way using the optimized_diameter function
    int height = 0;
    cout << optimized_diameter(root, &height) << endl;
}