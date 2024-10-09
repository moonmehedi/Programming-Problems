#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   // vector<int>v(n);
    priority_queue<int,vector<int>,greater<int>>min_heap;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        min_heap.push(a);
    }

    int ans=0;
    while(min_heap.size()>1){//until one element is left
        int a=min_heap.top();
        min_heap.pop();
        int b=min_heap.top();
        min_heap.pop();
        //pop two element add them store value in ans
        ans+=a+b;

        min_heap.push(a+b);//push the added element in heap

    }

    cout<<ans<<endl;

}