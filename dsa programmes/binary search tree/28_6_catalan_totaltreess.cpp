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

vector<node *> constructTrees(int start, int end)
{
    vector<node *> trees;

    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<node *> leftSubtrees = constructTrees(start, i - 1);
        vector<node *> rightSubtrees = constructTrees(i + 1, end);

        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                node *right = rightSubtrees[k];
                node *n = new node(i);
                n->left = left;
                n->right = right;
                trees.push_back(n);
            }
        }
    }
    return trees;
}

signed main()
{
    fast_io(); // enable faster I/O
    vector<node *> trees = constructTrees(1, 3);

    return 0;
}