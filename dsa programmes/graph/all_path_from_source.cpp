#include<bits/stdc++.h>
using namespace std;

vector<int>adj[200];
vector<bool>visited(200);
//vector<int>


void dfs(int source,string s,int des){
if(source==des){
    cout<<s<<des<<endl;
    //s.clear();
    return ;
}

for(auto child:adj[source]){
    if(!visited[child]){
        visited[source]=1;
        dfs(child,s+to_string(source),des);
        visited[source]=false;
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

    //for(int i=0;i<nodes;i++){
        //if(!visited[i]){
            dfs(0,"",5);
        
   // }
}