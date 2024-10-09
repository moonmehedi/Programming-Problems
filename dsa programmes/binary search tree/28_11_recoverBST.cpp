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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointer(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
        return;

    calcPointer(root->left, first, mid, last, prev);
    if (*prev and root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, first, mid, last, prev);
}

void restoreBST(node *root)
{
    node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    // utility fun
    calcPointer(root, &first, &mid, &last, &prev);

    // case1
    if (first and last) /* if first and last not null*/
        swap(&(first->data), &(last->data));
    else if (first and last)
        swap(&(first->data), &(mid->data));
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

signed main()
{
    fast_io(); // enable faster I/O

    //           6
    //         /   \
    //        9      3
    //      /  \      \
    //    1     4      13

    node *root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorder(root);
    restoreBST(root);
    cout << endl;
    inorder(root);
    return 0;
}