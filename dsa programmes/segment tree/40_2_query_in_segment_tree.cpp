#include<bits/stdc++.h>
using namespace std;
int n=1e5;
vector<int>a(n);
vector<int>tree(4*n);

void build(int tree_node,int start,int stop){
    //when low ==high means it's on leaf node
    if(start==stop){ 
        //update the tree_index with array's value
        tree[tree_node]=a[start];
        return;
    }

    int mid=(start+stop)/2;

    build(2*tree_node,start,mid);//build left subtree
    build(2*tree_node+1,mid+1,stop);//build right subtree

    //from the value of left child and right child update this current nodes value
    tree[tree_node]=tree[2*tree_node]+tree[2*tree_node+1];
}
int main(){
   a={5,3,2,4,1,8,6,10};

    build(1,0,7);

    for(int i=1;i<15 ;i++){
        cout<<tree[i]<<" ";
    }
}