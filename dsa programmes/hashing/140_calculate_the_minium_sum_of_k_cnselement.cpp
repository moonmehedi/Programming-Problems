#include<bits/stdc++.h>
using namespace std;
int main(){

    
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int sum=0;
    int ans=INT_MAX;
    for(int i=0;i<k;i++){
        sum+=v[i];
    }
    ans=sum;
    for(int i=k;i<n;i++){
        sum=sum+v[i]-v[i-k];
        if(sum<ans){
            ans=sum;
        }
    }
    cout<<ans<<endl;

}