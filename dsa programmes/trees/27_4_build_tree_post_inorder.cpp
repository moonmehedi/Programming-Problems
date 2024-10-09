/*
This program implements a function to construct a binary tree from its inorder and postorder traversals, and then performs a preorder traversal of the constructed tree.

The program defines a class node which represents a node in the binary tree. Each node has an integer data value, and pointers to its left and right child nodes.

The program also defines a search function which searches for an integer curr in an array inorder between indices start and end. It returns the index of curr in the array inorder.

The main function of the program is the build_tree_post_in function which takes as input the postorder and inorder traversals of a binary tree, along with the starting and ending indices of the inorder array. The function recursively constructs the binary tree and returns a pointer to the root node of the constructed tree. The function works as follows:

If the starting index start is greater than the ending index end, return NULL as there are no nodes to construct.
The idx variable is used to keep track of the index of the current node in the postorder array. We start by setting it to the last index end of the postorder array.
The curr variable is set to the value at the current index in the postorder array postorder[idx].
A new node is created with value curr and its left and right pointers are set to NULL.
The pos variable is set to the index of curr in the inorder array using the search function.
The right subtree is constructed recursively by calling the build_tree_post_in function with parameters postorder, inorder, pos+1 and end. The right subtree is constructed first because the postorder traversal visits the root node last, and the right subtree comes before the left subtree in the postorder traversal.
The left subtree is constructed recursively by calling the build_tree_post_in function with parameters postorder, inorder, start and pos-1. The left subtree is constructed after the right subtree because the postorder traversal visits the nodes in the left subtree before visiting the root node.
Finally, the preoder_traversal function is called to perform a preorder traversal of the constructed binary tree. The preoder_traversal function prints the data values of the nodes in the binary tree in preorder fashion.

The program creates a binary tree from the following postorder and inorder traversals:

Postorder: 4, 5, 2, 6, 7, 3, 1
Inorder: 4, 2, 5, 1, 6, 3, 7
The resulting binary tree is then traversed in preorder fashion, which outputs the following sequence of values:

1 2 4 5 3 6 7

*/

#include <bits/stdc++.h>
using namespace std;

// define a node class for binary tree
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

// function to search an element in inorder traversal
// start and end are the indices of the current subarray in inorder traversal
int search(int inorder[], int start, int end, int curr)
{
    // iterate through the subarray to find the index of the current element
    while (start <= end)
    {
        if (inorder[start] == curr)
        {
            return start;
        }
        start++;
    }
    // if the current element is not found, there is an error in input
    cout << "Invalid output";
    return -1;
}

// function to build binary tree from postorder and inorder traversals
// start and end are the indices of the current subarray in inorder traversal
node *build_tree_post_in(int postorder[], int inorder[], int start, int end)
{
    // base case: if the subarray is empty, return null
    if (start > end)
    {
        return NULL;
    }
    // current node is the last element of postorder traversal
    static int idx = end; // use static variable to keep track of current index in postorder traversal
    int curr = postorder[idx];
    idx--;
    // create a new node with the current element
    node *root = new node(curr);
    // find the index of the current element in inorder traversal
    int pos = search(inorder, start, end, curr);
    // build right subtree first since the last element in postorder traversal is the root of right subtree
    root->right = build_tree_post_in(postorder, inorder, pos + 1, end);
    // build left subtree after right subtree is built
    root->left = build_tree_post_in(postorder, inorder, start, pos - 1);
    // return the current node
    return root;
}

// function to perform preorder traversal of binary tree
void preoder_traversal(node *root)
{
    // base case: if the node is null, return
    if (root == NULL)
    {
        return;
    }
    // print the data of the current node
    cout << root->data << " ";
    // traverse left subtree recursively
    preoder_traversal(root->left);
    // traverse right subtree recursively
    preoder_traversal(root->right);
}

// main function to test the implementation
int main()
{
    // define the postorder and inorder traversals of the binary tree
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    // build the binary tree from the traversals
    node *root = build_tree_post_in(postorder, inorder, 0, 6);
    // perform preorder traversal of the binary tree
    preoder_traversal(root);
}