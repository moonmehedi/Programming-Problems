#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == NULL and right != NULL)
            return false;
        if (left != NULL and right == NULL)
            return false;
        if (left == NULL and right == NULL)
            return true;

        return (left->val == right->val) and isMirror(left->left, right->right) and isMirror(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {

        if (root == NULL)
            return false;

        return isMirror(root->left, root->right);
    }
};