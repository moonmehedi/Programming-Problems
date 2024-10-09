#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,g;
        cin>>n>>g;
        int arr[n],diff[n-1];
        cin>>arr[0];
        for(int i=1;i<n;i++){
            cin>>arr[i];
            diff[i-1]=abs(arr[i-1]-arr[i]);
        }
    sort(diff,diff+n-1,greater<int>());
    int sum=0;
    for(int i=g-1;i<n-1;i++){
        sum+=diff[i];
    }
    cout<<sum<<endl;
    }
}