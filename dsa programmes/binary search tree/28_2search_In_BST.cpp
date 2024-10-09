#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

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

/*here fucniton dont take root by reference */
node *build_tree(node *root, int val)
{
    /*if root becomes null add the node and retunr*/
    if (root == NULL)
    {
        /*create a new node add val and return*/
        node *root = new node(val);
        return root;
    }
    // if val is small than node add it to left
    if (root->data > val)
    {
        root->left = build_tree(root->left, val);
    }
    /*if val is greater than node add it to the right */
    else if (root->data < val)
    {
        root->right = build_tree(root->right, val);
    }

    /*retunr the current root of this recursion to previous recursive calls*/
    return root;
}

bool search_BST(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    else if (root->data > key)
    {
        return search_BST(root->left, key);
    }
    else // root->data<key
    {
        return search_BST(root->right, key);
    }
}

signed main()
{
    fast_io(); // enable faster I/O
               // Create a binary tree
    node *root = NULL;
    /* as the funciton dont take root by reference we have to store root*/
    root = build_tree(root, 5);
    build_tree(root, 1);
    build_tree(root, 3);
    build_tree(root, 4);
    build_tree(root, 2);
    build_tree(root, 7);

    cout << search_BST(root, 7);
    return 0;
}