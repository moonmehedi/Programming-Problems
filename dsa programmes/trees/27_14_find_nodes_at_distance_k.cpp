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

// case 1
void printsubtreenodes(node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }

    printsubtreenodes(root->left, k - 1);
    printsubtreenodes(root->right, k - 1);
}

// case 2
int print_node_at_k(node *root, node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    // handled the case when root == target
    if (root == target)
    {
        // from this target node we have to print all node at distance k
        printsubtreenodes(root, k);
        return 0;
    }

    // this below code finds the targer in left or right subtree
    int dl = print_node_at_k(root->left, target, k);
    // it means we found our target in left subtree
    if (dl != -1)
    {
        // this means root is an ancestor and distance from target node to root is k
        // in this case print root
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            // else root is an ancestor and distance from current node to root is not k
            // in this case print nodes at distance k from root's right subtree as target is at roots's left
            // here (-2 is add) because target to root is 1 and that root to root.left another 1
            printsubtreenodes(root->right, k - dl - 2);

        // add the root in dl and return it it recursive calls
        return 1 + dl;
    }

    // this below code finds the targer in  right subtree
    int dr = print_node_at_k(root->right, target, k);
    // it means we found our target in right subtree
    if (dr != -1)
    {
        // this means root is an ancestor and distance from target node to root is k
        // in this case print root
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
            // else root is an ancestor and distance from current node to root is not k
            // in this case print nodes at distance k from root's right subtree as target is at roots's left
            // here (-2 is add) because target to root is 1 and that root to root.left another 1
            printsubtreenodes(root->left, k - dr - 2);

        // add the root in dr and return it it recursive calls
        return 1 + dr;
    }

    // if target node is not available in the tree
    return -1;
}

int main()
{
    // Create a binary tree with seven nodes
    node *root = new node(1);
    root->left = new node(2);
    node *target = root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    print_node_at_k(root, target, 1);
}