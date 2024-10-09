#include<bits/stdc++.h>
using namespace std;
bool is_sorted(int arr[],int size,int i){
   // if(i==size-2) return true;
    if(arr[i]>arr[i+1]) return false;
    if(i==size-2) return true;
    return is_sorted(arr,size,i+1);
}
int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<is_sorted(arr,n,0)<<endl;
}