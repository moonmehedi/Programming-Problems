#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

/*

The algorithm finds the largest Binary Search Tree (BST) in a Binary Tree. To do so, it recursively traverses the Binary Tree in a bottom-up manner. At each step, it computes the information of the BST rooted at the current node, using the information of the left and right subtrees.

The information computed for each node includes:

size: the number of nodes in the subtree rooted at the current node.
max: the maximum value in the subtree rooted at the current node.
min: the minimum value in the subtree rooted at the current node.
ans: the size of the largest BST in the subtree rooted at the current node.
isBST: a boolean indicating whether the subtree rooted at the current node is a valid BST.
If the left and right subtrees are both valid BSTs and the current node satisfies the BST property (its value is greater than the maximum value in the left subtree and less than the minimum value in the right subtree), then the subtree rooted at the current node is also a valid BST. In this case, the information computed for the current node is updated with the size of the subtree and the maximum and minimum values.

The final result is the maximum size of a valid BST among all the nodes in the Binary Tree. This value is computed by taking the maximum of the ans field in the information computed for each node.


approach

The algorithm finds the largest binary search tree (BST) in a given binary tree.

The algorithm works as follows:

If the root is NULL, return an object with size = 0, max = INT_MIN, min = INT_MAX, ans = 0, and isBST = true.
If the root has no left or right child, return an object with size = 1, max = root->data, min = root->data, ans = 1, and isBST = true.
Recursively find the largest BST in the left and right subtrees by calling the function itself for the left and right children.
Create a new object "curr" with size = 1 + leftinfo.size + rightinfo.size.
If both left and right subtrees are BSTs, and the root value is greater than the maximum value of the left subtree and less than the minimum value of the right subtree, then the current subtree is also a BST. In this case, update curr.min and curr.max to the minimum and maximum values of the current subtree, set curr.ans = curr.size, and curr.isBST = true. Return curr.
Otherwise, the current subtree is not a BST. In this case, set curr.ans to the maximum of the left and right subtree's ans values, set curr.isBST to false, and return curr.
Finally, the ans field of the returned object from the top-level call to the function will contain the size of the largest BST in the binary tree.
*/

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

struct info
{
    int size;   // size of the current subtree
    int max;    // maximum value in the current subtree
    int min;    // minimum value in the current subtree
    int ans;    // size of the largest BST in the current subtree
    bool isBST; // whether the current subtree is a BST or not
};

// Function to find the largest BST in a binary tree
info largestBSTinBT(node *root)
{
    if (root == NULL)
    {
        // Base case: empty tree
        return {0, INT_MIN, INT_MAX, 0, true};
    }

    if (root->left == NULL and root->right == NULL)
    {
        // Base case: leaf node
        return {1, root->data, root->data, 1, true};
    }

    // Recursively find the largest BST in the left and right subtrees
    info leftinfo = largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);

    // Create a new info object for the current subtree
    info curr;
    curr.size = 1 + leftinfo.size + rightinfo.size;

    // Check if the current subtree is a BST
    if (leftinfo.isBST and rightinfo.isBST and (root->data > leftinfo.max and root->data < rightinfo.min))
    {
        // If the current subtree is a BST, update curr accordingly
        curr.min = min(root->data, min(leftinfo.min, rightinfo.min));
        curr.max = max(root->data, max(leftinfo.max, rightinfo.max));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    // If the current subtree is not a BST, update curr accordingly
    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    return curr;
}

signed main()
{
    fast_io(); // enable faster I/O

    // Create a sample binary tree
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    // Find the largest BST in the binary tree and print its size
    cout << "largest BST " << largestBSTinBT(root).ans << endl;

    return 0;
}