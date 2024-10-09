#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;    // Data stored in the node
    node *left;  // Pointer to the left child of the node
    node *right; // Pointer to the right child of the node

    // Constructor to initialize a node with the given value and null left and right pointers
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool get_path(node *root, vector<int> &path, int n1)
{

    // if root is null recursion reaches the end of the code so return false
    if (root == NULL)
        return false;

    path.push_back(root->data);
    // if data found return true to recursive call
    if (root->data == n1)
    {
        return true;
    }
    // if the above if condition finds the data it will return true
    // if for any get_path fucntion below the above function found true then next line will be executed
    // purpose of this line is not to pop the path if the root is found because it the below statement is true in all previous recursive call it will return true and below lines will not be executed
    if (get_path(root->left, path, n1) or get_path(root->right, path, n1))
        return true;

    // if data not found below code will be executed
    // if data is not found then we have to erase the path
    path.pop_back();
    return false;
}

int lca(node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (root == NULL)
        return 0;

    // here i will be sending root as i dont know at which subtree n1 or n2 may fall
    // if one of the n1 or n2 not found return -1
    // and return
    if (!get_path(root, path1, n1) || !get_path(root, path2, n2))
    {
        return -1;
    }

    // if both the n1 and n2 found then execute below
    // traverse path n1 and n2 and find the diverse point
    int i;
    for (i = 0; i < path1.size() and path2.size(); i++)
    {
        // diverse point
        if (path1[i] != path2[i])
            break;
    }
    // return value of diverse point
    return path1[--i];
}

// approach two
node *lca2(node *root, int n1, int n2)
{
    // if reach the end return the end
    if (root == NULL)
    {
        return NULL;
    }
    // if data matches n1 or n2 return the found root
    if (root->data == n1 or root->data == n2)
    {
        return root;
    }

    // search for n1 and n2 in both tree if one of them is found ,store address and return the address in recursive call.
    node *left_lca = lca2(root->left, n1, n2);
    node *right_lca = lca2(root->right, n1, n2);

    // if both the lca is found this code will executed and it will return the root in recursice call
    if (left_lca != NULL and right_lca != NULL)
    {
        return root;
    }

    // if one lca is found then this call will return that one lca in recursive call until both lca is found
    if (left_lca != NULL)
        return left_lca;
    else
        return right_lca;
}
int main()
{
    // Create a binary tree with seven nodes
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << lca(root, 4, 6) << endl;

    cout << lca2(root, 4, 6)->data << endl;
}