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
/***********MY CODE***************/
// this algo takes root and min and max value
// if root is between min and max valid
// check if right and left is valid too
// if one recursion return false the whole recursion will return false
bool isBST(node *root, int min, int max)
{

    // if root null valid bst return ture
    if (root == NULL)
        return true;
    // if root data in between min max valid node
    else if (root->data > min and root->data < max)
    {
        // check if all nodes are valid
        // return true if left and rigth recursion call return true
        // if one node becaumes invalid then the total recursion call becomes falles
        return isBST(root->left, min, root->data) and isBST(root->right, root->data, max);
    }

    // if the node is not valid return false
    return false;
}

// 2nd approach
// in this case we will be sending the root node to its subtree
bool checkBST(node *root, node *min, node *max)
{
    // if null tree valid
    if (root == NULL)
        return true;

    // if root less than min reutrn false
    if (min != NULL and root->data <= min->data)
        return false;

    // if root greater than max return true
    if (max != NULL and root->data >= max->data)
        return false;

    // check for rest of the trees
    bool isleft_valid = checkBST(root->left, min, root);
    bool isright_valid = checkBST(root->right, root, max);

    // if left and right both the trees are true return true
    // if one becomes false return false
    return isleft_valid and isright_valid;
}

node *buildBST(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }

    if (key < root->data)
    {
        root->left = buildBST(root->left, key);
    }
    if (key > root->data)
    {
        root->right = buildBST(root->right, key);
    }
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
    node *root = NULL;
    root = buildBST(root, 7);
    buildBST(root, 5);
    buildBST(root, 6);
    buildBST(root, 4);
    buildBST(root, 2);
    buildBST(root, 3);
    buildBST(root, 8);
    buildBST(root, 12);
    buildBST(root, 11);
    // root->left->right = new node(36);
    inorder(root);
    cout << endl;
    cout << isBST(root, INT_MIN, INT_MAX);
    cout << endl;
    cout << checkBST(root, NULL, NULL);
}