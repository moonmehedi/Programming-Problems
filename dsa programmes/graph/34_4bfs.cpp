

/*
graph
         1
      /   \
    2      3
  / |\ \  /
 4  5 6 7

*/

#include <bits/stdc++.h>
using namespace std;

bool vis[100];
vector<int> adj_list[100];
int main()
{

    for(int i=0;i<100;i++){
        vis[100]==false;
    }

    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;

    for (int i = 0; i < number_of_edges; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for (auto i : adj_list[node])
        {
            if (vis[i] == false)
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}