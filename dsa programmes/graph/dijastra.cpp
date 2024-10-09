#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt;

    Edge(int s, int d, int w)
    {
        src = s;
        dest = d;
        wt = w;
    }
};

vector<Edge> graph[2000];
int dist[2000];
bool visited[2000];

void dijkstra(int src, int edges)
{
    priority_queue<pair<int, int>> q;

    for (int i = 0; i < edges; i++)
    {
        if (i != src)
            dist[i] = INT_MAX;
    }
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> curr = q.top();
        q.pop();
        if (!visited[curr.second])
        {

            for (auto neighbour_edge : graph[curr.second])
            {
                int u = neighbour_edge.src;
                int v = neighbour_edge.dest;
                if (dist[u] + neighbour_edge.wt < dist[v])
                {
                    dist[v] = dist[u] + neighbour_edge.wt;
                    q.push({dist[v], v});
                }
            }
        }
    }

    for (int ele : dist)
    {
        cout << ele << " ";
    }
}

int main()
{
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s].push_back(Edge(s, d, w));
    }

    dijkstra(0, edges);
}