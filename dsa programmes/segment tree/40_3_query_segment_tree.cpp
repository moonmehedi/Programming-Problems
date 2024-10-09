#include<bits/stdc++.h>
using namespace std;

int N=1e5;
vector<int> a(N);
vector<int>tree(4*N);

void build(int tree_node,int start,int stop){
    if(start==stop){
        tree[tree_node]= a[start];
        return;
    }
    int mid=(start+stop)/2;
    build(2*tree_node,start,mid);
    build(2*tree_node+1,mid+1,stop);

    tree[tree_node]=tree[2*tree_node]+tree[2*tree_node+1];
}

int query(int tree_node,int start,int stop,int left,int right){
    if(stop<left or start>right){//when out of range
    return 0;
    }
    else if(left<=start and stop<=right){//when complete segment
     return tree[tree_node];
    }
    else{//when partial segment

    //use recusive calls to until complete segment or out of range found

    int mid=(start+stop)/2;
    int left_sum=query(2*tree_node,start,mid,left,right);
    int right_sum=query(2*tree_node+1,mid+1,stop,left,right);

    return left_sum+right_sum;


    }
}

void update(int tree_node,int start,int stop,int pos,int diff){
    if(start>pos || pos>stop){//smaller than start and greater than stop then not in range
        return;
    }

    tree[tree_node]+=diff;//add the difference to related tree nodes
    //here we are adding the difference to large nodes then sequentially going to leaf nodes

    if(start!=stop){//not leaf noed
    int mid=(start+stop)/2;
    update(2*tree_node,start,mid,pos,diff);
    update(2*tree_node+1,mid+1,stop,pos,diff);

    }
}

int main(){
    int n;

    cin>>n;

    a.resize(n);


    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(1,0,n-1);

    while(true){
        int ch;
        cin >>ch;
        if(ch==1){//ask query
        int left,right;
        cin>>left>>right;

        int ans=query(1,0,n-1,left,right);
        cout<<ans<<endl;

        }

        if(ch==2){
            int pos,val;
            cin>>pos>>val;

            int diff=val-a[pos];
            a[pos]=val;
            update(1,0,n-1,pos,diff);

            cout<<query(1,0,n-1,1,6);
        }

        if(ch==0){
            break;
        }
    }
}