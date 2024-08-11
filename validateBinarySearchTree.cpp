#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long
#define endl '\n'

// /**
//  * Definition for a binary tree node.
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
public:

    bool rec(TreeNode* root,TreeNode* min,TreeNode *max){
        if(root==NULL)
            return true;

        if(min!=NULL and root->val<=min->val){
            return false;
        }
        if (max != NULL and root->val >= max->val){
            return false;
        }

        return rec(root->left, min, root) and rec(root->right, root, max);
    }

    bool isValidBST(TreeNode *root)
    {
        return rec(root, NULL, NULL);
    }
};

signed main()
{
    fast_io();
    // Your code here
}
