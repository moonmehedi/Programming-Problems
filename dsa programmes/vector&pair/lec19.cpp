#include<bits/stdc++.h>
using namespace std;
//if comparator true not replace if not replace
bool mycomparator(pair<int,int> p1,pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){
    int arr[]={10,16,7,14,5,3,12,9};
    vector <pair <int , int >> moon;
    for(int i=0;i<sizeof(arr)/sizeof(arr[1]);i++){
        //moon[i]={arr[i],i} not valid
        //you can also use make_pair(arr[i],i)
     moon.push_back({arr[i],i});
    }

    sort(moon.begin(),moon.end(),mycomparator);
    for(int i=0;i<moon.size();i++){
        arr[moon[i].second]=i;
    }
    for(int i=0;i<moon.size();i++){
       cout<<arr[i]<<" ";
    }
}
