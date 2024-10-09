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

// here we will be using two pointer start and stop
// find mid using start and stop build mid node and call left and right subtree for it
// in left subtree start will be unchanged but stop will be mid-1;
// in right subtrr start will be mid+1 and stop will be unchanged
// if start>stop return null
node *buildBST_from_sorted_array(node *root, int arr[], int start, int stop)
{
    // in valid node node here return null
    if (start > stop)
    {
        return NULL;
    }
    // find the mid element
    int idx = (start + stop) / 2;
    // build node using mid element
    root = new node(arr[idx]);

    // for that node build it's left and right subtree
    root->left = buildBST_from_sorted_array(root->left, arr, start, idx - 1);
    root->right = buildBST_from_sorted_array(root->right, arr, idx + 1, stop);

    // return  the root of the tree
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    node *root = buildBST_from_sorted_array(NULL, arr, 0, 4);

    inorder(root);
}