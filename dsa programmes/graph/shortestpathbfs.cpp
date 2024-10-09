#include<bits/stdc++.h>
using namespace std;


vector<int>adj[2000];
int path[2000];
int visited[2000];
int parent[2000];
char arr[13]={'0','a','b','c','d','e','f','g','h','i','j','k','l'};

void bfs(int src){
    queue<int>q;
    q.push(src);
    path[src]=0;
    visited[src]=1;
    parent[src]=src;

    while (!q.empty())
    {
        int top=q.front();
        q.pop();cout<<top<<" "; 
        for(auto child:adj[top]){
            if(!visited[child]){
                visited[child]=1;
                path[child]=path[top]+1;
                parent[child]=top;
                q.push(child);
            }
        }
        }
    
}


void printpath(int dest){
    if(parent[dest]==dest){
        cout<<arr[dest]<<endl;
        return;
    }
    printpath(parent[dest]);
    cout<<arr[dest]<<endl;

}
int main(){

    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    for(int i=1;i<=v;i++){
        if(!visited[i]){
            bfs(i);
        }
    }

int src,dest;
cin>>src>>dest;
 printpath(dest);

}