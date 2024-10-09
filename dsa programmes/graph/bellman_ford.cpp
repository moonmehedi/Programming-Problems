#include <bits/stdc++.h>
using namespace std;

int dist[1000];

class edge
{
public:
    int src;
    int dest;
    int wt;

    edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

vector<edge> graph[1000];

void bellmanford(int vertecs, int src)
{
    for (int i = 0; i < vertecs; i++)
    {
        if (i != src)
            dist[i] = INT_MAX;
    }

    for (int i = 0; i < vertecs - 1; i++)
    {
        for (auto node : graph)
        {
            for (auto neighbour_edges : node)
            {
                edge e = neighbour_edges;
                int u = e.src;
                int v = e.dest;
                if (dist[u] + e.wt < dist[v])
                    dist[v] = dist[u] + e.wt;
            }
        }
    }

    for (auto node : graph)
    {
        for (auto neighbour_edges : node)
        {
            edge e = neighbour_edges;
            int u = e.src;
            int v = e.dest;
            if (dist[u] + e.wt < dist[v])
            {
                cout << "negative cycle " << endl;
                return;
            }
        }
    }

    for (int i = 0; i < 10; i++)
        cout << dist[i] << " ";
}

int main()
{
    int edges, vertecs;
    cin >> edges >> vertecs;

    for (int i = 0; i < edges; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back(edge(s, d, w));
    }

    bellmanford(vertecs, 0);
}