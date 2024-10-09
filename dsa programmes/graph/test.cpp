#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph(200);

vector<int> dist(200, INT_MAX);
vector<int> daddy(200);

int main()
{

    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int node1, node2, weight;
        cin >> node1 >> node2 >> weight;

        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});
    }

    int source,node;
    cin>>source>>node;


    set<pair<int,int>>s;
    s.insert(0,source);

    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);

        for(auto child:graph[x.second]){
            if(dist[child.first]>dist[x.second]+child.second){
                s.erase({dist[child.first],child.first});
                dist[child.first]=dist[x.second]+child.second;
                s.insert({dist[child.first],child.first});
                daddy[child.first]=x.second;
            }
        }
    }
}