#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;

    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    map<int,int> m;

    int count=0;
    for(int i=0;count<k;i++){
        if(m[v[i]]==0){
            count++;
        }
        m[v[i]]++;
}

map<int,int>::reverse_iterator it;
for(it=m.rbegin();it!=m.rend();it++){
    cout<<it->first<<" "<<it->second<<endl;
}

}