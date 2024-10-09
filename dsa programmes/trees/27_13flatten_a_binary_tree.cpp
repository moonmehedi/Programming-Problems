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


//code for flatten a tree

/*
we will be swithing a trees link into a link list in preorder direction to its right
1/if root left is not null then we have to flatten the left subtree
2/after flatten the left subtree store right subtree in a variable call temp
3/put the flatten left subtree in roots right and make roots left subtree null
4/add temp at the end of roots right subtree

*/
void flatten(node *root)
{
//if root becomes null or roots right and left both becomes null then subtree already flatten return
    if (root == NULL or (root->left == NULL and root->right == NULL))
    {
        return;
    }
    //if root left not NULl in this case we have to flatten the left subtree
    if (root->left != NULL)
    {

        //flatten the left subtree
        flatten(root->left);
        //store roots right in a variable temp
        node *temp = root->right;
        //replace left subtree in root right
        root->right = root->left;
        //make root left subtree null
        root->left = NULL;
        /*traverse at the end of the recently add root right*/
        node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        //add temp at the end of the roots right
        t->right = temp;
    }

    //search in roots right subtree for any not flatten left subtree
    flatten(root->right);
}


//print linked list
void print(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << endl;
    print(root->right);
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

    flatten(root);
    print(root);
}