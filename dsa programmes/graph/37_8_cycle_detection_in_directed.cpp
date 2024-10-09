#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);
vector<int> visited(200);
vector<bool> Stack(200);
bool is_present = false;
bool iscycle(int src, int parent)
{
    Stack[src] = true;
    visited[src] = true;

    for (auto i : adj[src])
    {
        if (Stack[i])//means already in the stack
        {
            return true;
        }
        else if (!visited[i] and iscycle(i, src))
            return true;
    }

    Stack[src]=false;
    return false;
}

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
    }

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i] and iscycle(i, -1))
        {
            is_present = true;
        }
    }

    if (is_present)
    {
        cout << "cycle is present " << endl;
    }
    else
    {
        cout << "cycle is not present " << endl;
    }
}