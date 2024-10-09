#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    /*an n size array*/
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&1<<j)
            cout<<arr[j];
        }
        cout<<endl;
    }

}