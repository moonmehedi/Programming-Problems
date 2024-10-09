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
// build from preorder
node *buildBSTpreorder(int preorder[], int *preorderidx, int key, int min, int max, int n)
{
    // if out of bound return
    if (*preorderidx >= n)
        return NULL;
    // set root to NUll
    node *root = NULL;
    // if key is valid set it to root
    if (key > min and key < max)
    {
        // create node with key
        root = new node(key);
        // increase next index
        *preorderidx = *preorderidx + 1;

        if (*preorderidx < n)
            // sent next index as key and max to current  key for left subtree
            root->left = buildBSTpreorder(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        if (*preorderidx < n)
            // sent next index as key and min to current key for right subtree
            root->right = buildBSTpreorder(preorder, preorderidx, preorder[*preorderidx], key, max, n);
    }
    // return key
    return root;
}
void preorder_print(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}
int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int preorderidx = 0;
    node *root = buildBSTpreorder(preorder, &preorderidx, preorder[0], INT_MIN, INT_MAX, 5);
    preorder_print(root);

    return 0;
}