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

struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largestBSTinBT(node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL and root->right == NULL)
        return {1, root->data, root->data, 1, true};

    info leftinfo = largestBSTinBT(root->left);
    info rightinfo = largestBSTinBT(root->right);

    info curr;
    curr.size = 1 + leftinfo.size + rightinfo.size;
    if (leftinfo.isBST and rightinfo.isBST and (root->data > leftinfo.min and root->data < rightinfo.max))
    {
        curr.min = min(root->data, min(leftinfo.min, rightinfo.min));
        curr.max = max(root->data, max(leftinfo.max, rightinfo.max));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }

    curr.ans = max(leftinfo.ans, rightinfo.ans);
    curr.isBST = false;
    return curr;
}

signed main()
{
    fast_io(); // enable faster I/O

    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);
    cout << "largest BST " << largestBSTinBT(root).ans << endl;
    //  cout << "largest BST" << largestBSTinBT(root)<<endl;
    return 0;
}