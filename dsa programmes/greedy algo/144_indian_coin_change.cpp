#include<bits/stdc++.h>
using namespace std;

bool mycomparetor(int a,int b){
    return a>b;
    
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(),mycomparetor);
 
    int i=0;
    vector<pair<int,int>>ans;
    while(x!=0){
        int occurance=x/v[i];
        if(occurance>0){
            ans.push_back({v[i],occurance});
            x=x-occurance*v[i];
            i++;
        }
        else{
            i++;
        }
    }

    for(auto ele:ans){
        for(int i=0;i<ele.second;i++){
            cout<<ele.first<<" ";
        }
    }

}


/*this algo is for coin change */