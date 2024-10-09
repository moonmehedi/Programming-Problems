#include<bits/stdc++.h>
using namespace std;
int n=200;
vector<vector<int>> adj_list(n);
vector<int>is_visited(n);

bool dfs(int node,int parent){
    is_visited[node]=true;
    for(auto child:adj_list[node]){
        if(node!=parent){
        if(is_visited[child])
        return true;
        else if(!is_visited[child] and dfs(child,node)){
            return true;
        }
    }}
    return false;
}


int main(){

    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int node1,node2;
        cin>>node1>>node2;

        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    bool is_cycle=false;
    for(int i=0;i<nodes;i++){
        if(!is_visited[i] and dfs(i,-1)){
            is_cycle=true;
        }
    }



cout<<is_cycle<<endl;
}