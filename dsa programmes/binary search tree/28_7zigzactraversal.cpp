
// traver print nodes of one level to left to right and prints nodes of another level to right to left

/*

The code is an implementation of the zigzag traversal of a binary tree. The zigzag traversal is a type of level order traversal, where the nodes at even levels are printed from left to right and the nodes at odd levels are printed from right to left.

The code starts by defining a binary tree node class node, which has data, left, and right as its members. The data member stores the value of the node, while the left and right members point to the left and right child nodes, respectively.

The zigzagTraversal function takes a pointer to the root node of the binary tree as its argument and performs the zigzag traversal of the tree using two stacks currLevel and nextLevel.

Initially, the currLevel stack contains the root node. The function then enters a loop, where it pops nodes from the currLevel stack and prints their values. For each popped node, the function checks if it has any child nodes and adds them to the nextLevel stack. If the current level is being traversed from left to right, the left child node is added first to the nextLevel stack, followed by the right child node. If the current level is being traversed from right to left, the right child node is added first to the nextLevel stack, followed by the left child node.

Once all the nodes in the current level have been popped and processed, the function checks if the currLevel stack is empty. If it is empty, it means that all the nodes at the current level have been processed, and the function toggles the leftToright flag to switch the traversal direction. It then swaps the currLevel and nextLevel stacks, so that the nodes in the nextLevel stack become the nodes for the next level to be processed.
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

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// traver print nodes of one level to left to right and prints nodes of another level to right to left
// this function implements the zigzag traversal of a binary tree
void zigzagTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // use two stacks to store nodes on the current level and the next level
    stack<node *> currLevel;
    stack<node *> nextLevel;

    bool leftToright = true; // keep track of whether to print nodes from left to right or right to left

    currLevel.push(root); // start by pushing the root node to the current level stack

    while (!currLevel.empty()) // loop until all levels have been processed
    {
        node *temp = currLevel.top(); // get the top node from the current level stack
        currLevel.pop();              // pop the node from the current level stack

        if (temp)
        {
            cout << temp->data << " "; // print the node's data

            if (leftToright)
            {
                // if we are printing nodes from left to right, push the left child first and then the right child to the next level stack
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                // if we are printing nodes from right to left, push the right child first and then the left child to the next level stack
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        // if the current level stack is empty, we have finished processing the current level
        if (currLevel.empty())
        {
            leftToright = !leftToright; // toggle the printing direction for the next level
            swap(currLevel, nextLevel); // swap the current and next level stacks
        }
    }
}

signed main()
{
    fast_io(); // enable faster I/O

    // construct a binary tree
    //          12
    //         /    \
    //     9       15
    //     /  \
    // 5     10
    node *root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    zigzagTraversal(root); // call the function to perform zigzag traversal of the tree

    return 0;
}