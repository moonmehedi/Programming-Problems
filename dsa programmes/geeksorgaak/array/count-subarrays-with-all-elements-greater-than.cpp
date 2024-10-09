#include<bits/stdc++.h>
using namespace std;
int stop1(int i,int n,int k,int arr[]){
    
    int j;
    for( j=i;j<n;j++)
    {if(arr[j]<k)
    return j;
    }
    return j-1;
}
int main(){
    int n,k,start,stop,i;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for( i=0;i<n;i++)
    {
        if(arr[i]>k){
            start=i;
            stop=stop1(i,n,k,arr);
        
        for(int begin=start;begin<stop;begin++){
            for(int end=begin;end<stop;end++){
            for(int print=begin;print<=end;print++)
            {
                cout<<arr[print];
            }cout<<endl;
            }
        }}i=stop-1;
    }
}
