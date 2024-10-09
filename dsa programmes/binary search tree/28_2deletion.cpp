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

node *inordersucc(node *root)
{
    node *curr = root;
    while (curr and curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deletion(node *root, int val)
{
    // if (root == NULL)
    //     return NULL;
    if (root->data > val)
        root->left = deletion(root->left, val);
   else if (root->data < val)
        root->right = deletion(root->right, val);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = inordersucc(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    build_tree(root, 6);
    inorder(root);
    cout << endl;
    root = deletion(root, 2);
    inorder(root);

    return 0;
}