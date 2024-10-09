#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,s=0;
    string previous="moon",present;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>present;
        if(previous!=present) s++;
        previous=present;

    }
    cout<<s;
}