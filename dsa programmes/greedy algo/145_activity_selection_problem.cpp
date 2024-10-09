#include<bits/stdc++.h>
using namespace std;


bool mycomparetor(pair<int,int>&a,pair<int,int>&b){
    return a.second<b.second;
}

int main(){

    int n;
    cin>>n;//number of task
    vector<pair<int,int>>v(n);//vector to store start and end time of a particular task
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(),v.end(),mycomparetor);//sort array according to end time
    int task=1;//take the first task that end soon
    int end_time=v[0].second;//store ending time

    for(int i=1;i<n;i++){
        if(end_time<v[i].first){//see if the task overlap if dont take it
            task++;//take the task
            end_time=v[i].second;//update the new end time for new task
        }
    }

    cout<<task<<endl;//print total number of task that can be taken without overlapping
}