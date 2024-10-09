#include<bits/stdc++.h>
using namespace std;

vector<int>edge[200];
vector<bool>visited(200);
vector<int>parent(200),Distance(200);

int cost=0;

void prims_mst(int source){
    for(int i=1;i<200;i++){
        Distance[i]=INT_MAX;
    }

    set<vector<int>>s;
    s.insert({0,source});

    Distance[source]=0;

    while(!s.empty()){
        auto x=*(s.begin());
        visited[x.second]=true;
        s.erase(x);

        int u=x.second;
        int v=parent[x.second];
        int w=x.first;

        cout<<u<<" "<<v<<" "<<w<<endl;
        cost+=w;

        for(auto ele : edge[x.second]){

            if(visited[ele.first]){
                continue;
            }
            else if(Distance[ele.first]>ele.second){
                s.erase({Distance[ele.first],ele.first});
                Distance[ele.first]=ele.second;
                s.insert({Distance[ele.first],ele.first});
                parent[ele.first]=v;
            }
        }

    }
}

int main(){

    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int node1,node2,weight;
        cin>>node1>>node2>>weight;

        edge[node1].push_back({node2,weight});
        edge[node2].push_back({node1,weight});
    }

    prims_mst(1);
    cout<<cost<<endl;



}