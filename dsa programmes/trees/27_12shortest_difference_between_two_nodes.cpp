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

/*
idea:
1/find the lowest common ancestor of n1 and n2
2/find distance from n1 and n2 to lowest common ancestor d1 and d2
3/distance between this two nodes will be summetion of d1 and d2

*/

/*finding the lowest common ancestor */
/*this program hasbeen explain before */
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 or root->data == n2)
    {
        return root;
    }
    node *left_lca = lca(root->left, n1, n2);
    node *right_lca = lca(root->right, n1, n2);

    if (left_lca != NULL and right_lca != NULL)
    {
        return root;
    }
    if (left_lca != NULL)
    {
        return left_lca;
    }
    else
        return right_lca;
}

/* finding distance from lowest common ancestor to n1 */
/*
here
1/n1 can line in left subtree of root or right subtree of the root
2/we will take 3 parameter root n1 and d
3/initailly we will assume that n1 is available at that subtree and incerease d by one for every recursive call
4/at the end if root becomes null then n1 is not at that subtree so we will not return the distance instead that we return -1 means n1 not available in this path
5/if n1 is found then return the distance;
*/
int distance(node *root, int n1, int d)
{

    // if reach the end return -1
    if (root == NULL)
        return -1;

    // if n1 is found return distance from ancestor to n1 which is d;
    if (root->data == n1)
        return d;

    // in every recursive call find distance in the left or right subtree if found return d else retun -1
    int search_distance_in_left = distance(root->left, n1, d + 1);
    int search_distance_in_right = distance(root->right, n1, d + 1);

    // the purpose of this line of code is to return the distance through recursive call
    // if n1 is found one of left and right subtree  return the distance
    // means when a recursive call does not return -1 then return its value
    if (search_distance_in_left != -1)
        return search_distance_in_left;
    else
        return search_distance_in_right;
}

// retrun summeation of d1 and d2

// this fun put all the calls together
int difference_between_two_nodes(node *root, int n1, int n2)
{

    // find the lowest common ancestor
    node *lowest_common_ancestor = lca(root, n1, n2);

    // find the distance d1 and d2 from lca to n1,n2
    int d1 = distance(root, n1, 0);
    int d2 = distance(root, n2, 0);

    // return their summations
    return d1 + d2;
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
    cout << difference_between_two_nodes(root, 4, 7);

    return 0;
}