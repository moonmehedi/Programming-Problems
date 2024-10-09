#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200); // Adjacency list to store the graph
vector<int> v(200);           // Vector to store the visited nodes
vector<int> indegree(200);    // Vector to store the indegree of each node

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    v[start] = 1;

    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " "; // Print the element

        for (auto i : adj[element])
        {
            indegree[i]--;
            if (indegree[i] == 0 && v[i] == 0)
            {
                q.push(i);
                v[i] = 1;
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges; // Read the number of nodes and edges from input

    // Read the edges and populate the adjacency list
    for (int i = 1; i <= edges; i++)
    {
        int nodes1, nodes2;
        cin >> nodes1 >> nodes2;

        // Add the edge from nodes1 to nodes2
        adj[nodes1].push_back(nodes2);

        // Increment the indegree of nodes2 (for topological sorting)
        indegree[nodes2]++;
    }

    // Perform BFS for each component or disconnected node
    for (int i = 1; i <= nodes; i++)
    {
        if (v[i] == 0)
        {
            bfs(i);
        }
    }

    return 0;
}