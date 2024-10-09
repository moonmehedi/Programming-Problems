/*BINARY SEARCH*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,key;
    cout<<"ENTER SIZE OF ARRAY AND KEY";
    cin>>n>>key;
    int arr[n];
    cout<<"ENTER THE ARRAY?  ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int start=0,stop=n-1,m;start<=stop;m=(start+stop)/2){
        m=(start+stop)/2;
        if(arr[m]==key){
        cout<<"YES index :"<<m; return 0;}
        if(arr[m]<key)
        start=m+1;
        else
        stop=m-1;
    }
    cout<<"NO";

}