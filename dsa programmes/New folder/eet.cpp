#include <bits/stdc++.h>
using namespace std;
int n = 200;
vector<int> parent(200);
vector<int> sz(200);
void make_parent(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find_parent(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return parent[v] = find_parent(parent[v]); // set the leader as every ones parent
}

void Union(int u, int v)
{
    u = find_parent(u);
    v = find_parent(v);

    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] = sz[u] = sz[v];
    }
}
int main()
{
    int nodes, edge;
    cin >> nodes >> edge;
    vector<vector<int>> edges(nodes);
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v}); // means a vector of element = {u,v} will be push_backed
    }

    bool iscycle = false;

    for (auto ele : edges)
    {
        int u = ele[0];
        int v = ele[1];

        if (find_parent(u) == find_parent(v))
        {
            iscycle = true;
        }
        else
        {
            Union(u, v);
        }
    }

    cout << "hello" << endl;

    cout << iscycle << endl;
}
