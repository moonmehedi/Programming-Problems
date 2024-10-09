/*
Sure, I'd be happy to explain more about how the algorithm works.

The build_tree_in_pre function takes in three parameters - the preorder and inorder traversals of a binary tree, and the starting and ending indices of the inorder array for the current recursive call.

The function starts by checking if the start index is greater than the end index. If it is, it means that we have already constructed the entire binary tree for the current recursive call and we can return NULL.

The function then initializes a static variable idx to 0. This variable keeps track of the current index in the preorder array. We increment idx by 1 each time we use an element of the preorder array.

We then create a new node with the current element of the preorder array and set it as the root of the binary tree for the current recursive call.

Next, we search for the position of the root node in the inorder array. We do this because the inorder traversal of a binary tree will always have the left subtree of a node listed before the node itself, and the right subtree listed after the node. By finding the position of the root node in the inorder array, we can determine the boundaries of the left and right subtrees.

We then recursively call the build_tree_in_pre function on the left subtree, passing in the appropriate starting and ending indices for the left subtree of the current node. We set the left child of the root node to be the result of this recursive call.

We then recursively call the build_tree_in_pre function on the right subtree, passing in the appropriate starting and ending indices for the right subtree of the current node. We set the right child of the root node to be the result of this recursive call.

Finally, we return the root node of the binary tree for the current recursive call.

The preorder_traversal function simply performs a preorder traversal of the binary tree and prints out the data of each node. We pass in the root node of the binary tree to start the traversal.
*/

#include <bits/stdc++.h>
using namespace std;

// Define a class for a binary tree node
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

// Search for an element in the inorder array and return its position
int search(int inorder[], int start, int end, int curr)
{
    while (start <= end)
    {
        if (inorder[start] == curr)
        {
            return start;
        }
        start++;
    }
    // If the element is not found, print an error message and return -1
    cout << "Invalid output";
    return -1;
}

// Build a binary tree from its preorder and inorder traversals
node *build_tree_in_pre(int preorder[], int inorder[], int start, int end)
{
    // If the starting index is greater than the ending index, return NULL
    if (start > end)
    {
        return NULL;
    }
    
    // Use a static variable to keep track of the current element in the preorder traversal
    static int idx = 0;
    int curr = preorder[idx];
    idx++;
    
    // Create a new node for the current element
    node *root = new node(curr);
    
    // Find the position of the current element in the inorder traversal
    int pos = search(inorder, start, end, curr);
    
    // Recursively build the left and right subtrees
    root->left = build_tree_in_pre(preorder, inorder, start, pos - 1);
    root->right = build_tree_in_pre(preorder, inorder, pos + 1, end);
    
    // Return the root of the binary tree
    return root;
}

// Print the nodes of a binary tree in preorder traversal order
void preorder_traversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

int main()
{
    // Example usage of the build_tree_in_pre and preorder_traversal functions
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    node *root = build_tree_in_pre(preorder, inorder, 0, 6);
    preorder_traversal(root);
}


/*

*/