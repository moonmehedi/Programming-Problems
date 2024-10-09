#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200); // Adjacency list to store the graph
vector<int> v(200);           // Vector to store the visited nodes
vector<int> indegree(200);    // Vector to store the indegree of each node

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

    queue<int> q; // Queue to perform breadth-first traversal

    // Find the nodes with indegree 0 and add them to the queue
    for (int i = 1; i <= nodes; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Perform breadth-first traversal starting from nodes with indegree 0
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " "; // Print the element

        // Decrement the indegree of adjacent nodes and add them to the queue if indegree becomes 0
        for (auto i : adj[element])
        {
            indegree[i]--;
            // if nodes indegree becomes zero then add in the queue
            if (indegree[i] == 0)
                q.push(i);
        }
    }
}