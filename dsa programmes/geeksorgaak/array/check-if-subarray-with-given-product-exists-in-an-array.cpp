#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,key,p=1,k=0,i,j;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=k;k<n;i++){
    for(j=k;j<=i;j++){
        p=p*arr[j];
        }
        if(p==key)
          {
            cout<<"yes";
            for(int j=k;j<=i;j++){
                cout<<arr[j];
            }
            return 0;
          }
        p=1;
        if(i==n-1)
          i=++k;
    }
    cout<<"NO";
    }
