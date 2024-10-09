#include <bits/stdc++.h>
using namespace std;
#define edge pair<int, int>

class Graph
{
public:
    vector<pair<int, edge>> g;
    vector<pair<int, edge>> t;
    int parent[10];

    Graph(int v)
    {
        for (int i = 0; i < v; i++)
        {
            parent[i] = i;
        }
    }

    void AdEdge(int u, int v, int w)
    {

        g.push_back(make_pair(w, make_pair(u, v)));
    }

    int find_set(int i)
    {
        if (i == parent[i])
        {
            return i;
        }
        else
        {
            return find_set(parent[i]);
        }
    }

    void union_set(int u, int v)
    {
        parent[u] = parent[v];
    }

    void kruskal()
    {
        sort(g.begin(), g.end());
        int uRep, vRep, i;
        for (int i = 0; i < g.size(); i++)
        {
            int uRep = find_set(g[i].second.first);
            int vRep = find_set(g[i].second.second);
            if (uRep != vRep)
            {
                t.push_back(g[i]);
                union_set(uRep, vRep);
            }
        }
    }

    void print()
    {
        for (int i = 0; i < t.size(); i++)
        {
            cout << t[i].second.first << " " << t[i].second.second << " " << t[i].first << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.AdEdge(0, 1, 2);
    g.AdEdge(1, 4, 1);
    g.AdEdge(0, 2, 1);
    g.AdEdge(2, 3, 3);
    g.AdEdge(0, 3, 4);
    g.AdEdge(1, 3, 3);
    g.AdEdge(1, 3, 3);
    g.AdEdge(1, 2, 2);

    g.kruskal();
    g.print();
}