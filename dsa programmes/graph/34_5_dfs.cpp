#include <bits/stdc++.h>
using namespace std;

bool is_visited[100];
vector<int> adj_list[100];
vector<int> preorder_array, post_order_array;

void dfs(int root_node)
{

    // preorder
    is_visited[root_node] = true;
    preorder_array.push_back(root_node);

    // inorder
    for (auto node : adj_list[root_node])
    {
        if (is_visited[node] == false)
        {
            dfs(node);
        }
    }

    // post order

    post_order_array.push_back(root_node);
    return;
}

int main()
{
    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;

    for (int i = 0; i < 100; i++)
    {
        is_visited[i] == false;
    }

    for (int i = 0; i < number_of_edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    dfs(1);

    cout << "preorder sequence : " << endl;
    for (int i = 0; i < number_of_nodes; i++)
    {
        cout << preorder_array[i] << " ";
    }

    cout << endl
         << "post-order sequence : " << endl;

    for (int i = 0; i < number_of_nodes; i++)
    {
        cout << post_order_array[i] << " ";
    }
}