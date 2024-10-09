#include<bits/stdc++.h>
using namespace std;

vector<int >adj[200];
vector<bool>visited(200);


void dfs(int start,int nodes){
    visited[start]=true;
    cout<<start<<" ";

    for(auto child:adj[start]){
        if(!visited[child]){
            dfs(child,nodes);
        }
    }

}


int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int node1,node2;
        cin>>node1>>node2;


        adj[node1].push_back(node2);
        adj[node2].push_back(node1);

    }

    for(int i=0;i<=nodes;i++){
        if(!visited[i]){
            dfs(i,nodes);
        }
    }


}