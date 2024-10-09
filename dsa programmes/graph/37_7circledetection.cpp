#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(200);
vector<int> visited(200);
bool iscycle_present = false;

bool iscycle(int src, int parent)
{
    visited[src] = 1;
    for (auto ele : adj[src])
    {
        if (ele != parent)
        {
            if (visited[ele] == 1)
            {
                return true;
            }
            else if (!visited[ele] and iscycle(ele, src))
            {
                return true;
            }
        }
    }
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
        adj[node2].push_back(node1);
    }

    for (int i = 0; i < edges; i++)
    {
        if (!visited[i] and iscycle(i, -1))
        {
            iscycle_present = true;
        }
    }

    if (iscycle_present)
    {
        cout << "cycle present " << endl;
    }
    else
    {
        cout << "cycle is not present " << endl;
    }
}