#include<bits/stdc++.h>
using namespace std;
#define fast_io()             \
    ios_base::sync_with_stdio(false);\
    cin.tie(nullptr);   \
    cin.tie(nullptr)

const int n=1000;

int knapsack(int n,int w,vector<vector<int>> dp,int val[],int weight[]){
    if(w<=0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[w][n]!=-1){
        return dp[w][n];
    }
    if(weight[n-1]>w)
        dp[n][w]=knapsack(n-1,w,dp,val,weight);
    else
    dp[n][w]=max(knapsack(n-1,w,dp,val,weight),knapsack(n-1,w-weight[n-1],dp,val,weight)+val[n-1]);

    return dp[n][w];
}

signed main(){
    int iteam;
    cin>>iteam;
int val[iteam+1],weight[iteam+1];
vector<vector<int>> dp(100,vector<int>(100,-1));
    for(int i=0;i<iteam;i++){
        cin>>weight[i];
    }
    for(int i=0;i<iteam;i++){
        cin>>val[i];
    }
    int w;
    cin>>w;
    cout<<knapsack(iteam,w,dp,val,weight);

}