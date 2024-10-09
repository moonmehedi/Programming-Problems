#include <bits/stdc++.h>
using namespace std;

// Class for a binary tree node
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

// max path sum from one node to another
int maxpathsumutil(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    //find left and right sum
    int L_sum = maxpathsumutil(root->left, ans);
    int R_sum = maxpathsumutil(root->right, ans);

    //return max sum among 4 possible combo for a node
    int nodeMax = max(max(L_sum + root->data, R_sum + root->data), max(root->data, L_sum + R_sum + root->data));
    //return max among previous ans and present ans
    ans = max(ans, nodeMax);

    //keeping this a path not a tree
    return max(root->data, max(root->data + L_sum, root->data + R_sum));
}

int maxpathsum(node *root)
{
    int ans;
    maxpathsumutil(root, ans);
    return ans;
}

// my approach have little bug
int maxpathSum(node *root, int sum)
{
    if (root == NULL)
        return sum;
    if (root->data < 0)
    {
        int L_sum = maxpathSum(root->left, 0);
        int R_sum = maxpathSum(root->right, 0);
        return max(sum, max(L_sum, R_sum));
    }
    int lsum = maxpathSum(root->left, sum);
    int rsum = maxpathSum(root->right, sum);
    sum += root->data;

    return lsum + rsum + sum;
}

int main()
{
    // Create a binary tree with seven nodes
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(-3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    // cout << maxpathSum(root, 0);
    cout << maxpathsum(root);
}