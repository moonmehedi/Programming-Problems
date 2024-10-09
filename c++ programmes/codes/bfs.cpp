#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);
vector<int> visited(200);

void bfs(int start, int nodes)
{
    visited[start] = true;

    queue<int> family;
    family.push(start);

    while (!family.empty())
    {
        int x = family.front();
        cout << x << " ";
        family.pop();
        for (auto child : adj[x])
        {
            if (!visited[child])
            {
                visited[child] = true;
                family.push(child);
            }
        }
    }
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
        adj[node2].push_back(node1);
    }

    for (int i = 0; i <= nodes; i++)
    {
        if (!visited[i])
        {
            bfs(i, nodes);
        }
    }
}