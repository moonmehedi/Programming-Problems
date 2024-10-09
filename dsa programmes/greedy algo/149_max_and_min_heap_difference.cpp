#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int sum_large=0;
    int sum_small=0;
    for(int i=0;i<n/2;i++){
        sum_large+=(v[n-i-1]-v[i]);
        sum_small+=(v[2*i+1]-v[2*i]);
    }

    cout<<sum_large<<" "<<sum_small<<endl;


}