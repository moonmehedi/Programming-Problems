#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a;
        b[a-1]=i+1;
    }
    for(int i=0;i<n;i++){
        cout<<" "<<b[i];
    }
}