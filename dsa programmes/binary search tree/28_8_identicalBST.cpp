/*
The code you provided has two different functions to check if two binary trees are identical (isidentical1 and isIdentical2), so I'll explain both of them.

Function isidentical1:
This function uses a recursive approach to traverse the two trees and compare them node by node. The algorithm works as follows:

If both root1 and root2 are NULL, return true.
If only one of them is NULL, return false.
If both of them have the same value, recursively call the function with the left and right subtrees of root1 and root2.
If the condition in step 3 is not satisfied, return false.
Function isIdentical2:
This function also uses a recursive approach to traverse the two trees and compare them node by node. However, it has a slightly different implementation. The algorithm works as follows:

If both root1 and root2 are NULL, return true.
If only one of them is NULL, return false.
If both of them have the same value, recursively call the function with the left and right subtrees of root1 and root2.
If any of the conditions in step 2 or step 3 is not satisfied, return false.
The main difference between these two functions is in step 4. In isidentical1, if the condition in step 3 is not satisfied, the function immediately returns false. In isIdentical2, if any of the conditions in step 2 or step 3 is not satisfied, the function immediately returns false. In other words, isIdentical2 is a slightly more optimized version of isidentical1, as it has a shorter code path for the case where one of the trees is NULL.
*/
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

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// function to check if two binary trees are identical (approach 1)
bool isidentical1(node *root1, node *root2)
{
    // if both roots are NULL, they are identical
    if (root1 == NULL and root2 == NULL)
        return true;
    // if one root is NULL and the other is not, they are not identical
    else if (root1 == NULL || root2 == NULL)
        return false;

    // if both roots are not NULL, check if their data is equal
    if (root1->data == root2->data)
    {
        // recursively check the left and right subtrees
        return isidentical1(root1->left, root2->left) and isidentical1(root1->right, root2->right);
    }
    else
        return false; // data is not equal, so they are not identical
}

// function to check if two binary trees are identical (approach 2)
bool isIdentical2(node *root1, node *root2)
{
    // if both roots are NULL, they are identical
    if (root1 == NULL and root2 == NULL)
        return true;
    // if one root is NULL and the other is not, they are not identical
    else if (root1 == NULL or root2 == NULL)
        return false;

    // if both roots are not NULL, check if their data is equal
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical2(root1->left, root2->left);
        bool cond3 = isIdentical2(root1->right, root2->right);

        // return true if all conditions are satisfied
        return cond1 and cond2 and cond3;
    }
}

// Insert a node in the BST
node *insert(node *root, int data)
{
    if (root == NULL)
    {
        return new node(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

signed main()
{
    fast_io(); // enable faster I/O

    // create two binary search trees and insert nodes into them
    node *root1 = NULL;
    root1 = insert(root1, 5);
    insert(root1, 3);
    insert(root1, 2);
    insert(root1, 4);
    insert(root1, 7);
    insert(root1, 6);
    insert(root1, 8);

    node *root2 = NULL;
    root2 = insert(root2, 5);
    insert(root2, 3);
    insert(root2, 2);
    insert(root2, 4);
    insert(root2, 7);
    insert(root2, 6);
    insert(root2, 8);

    // call both functions to check if the trees are identical and print the result

    cout << isidentical1(root1, root2) << endl;
    cout << isIdentical2(root1, root2) << endl;
    return 0;
}