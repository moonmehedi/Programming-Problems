#include <bits/stdc++.h>
using namespace std;

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

int dist[100];
int visited[100];
vector<edge> graph[100];

void distra(int src, int edges)
{
    for (int i = 0; i < edges; i++)
    {
        if (i != src)
            dist[i] = INT_MAX;
    }

    priority_queue<pair<int, int>> q;

    q.push({src, 0});

    while (!q.empty())
    {
        pair<int, int> curr = q.top();
        q.pop();
        for (auto neighbout_edge : graph[curr.second])
        {
            edge e = neighbout_edge;
            int u = e.src;
            int v = e.dest;
            if (dist[u] + neighbout_edge.wt < dist[v])
            {
                dist[v] = dist[u] + neighbout_edge.w;
                q.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << dist[i] << " ";
    }
}

int main()
{
    int edges, verteces;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back(edge(s, d, w));
    }

    distra(0, edges);
}