#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int rec(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&dp){

        if(m==1 and n==1) return dp[m-1][n-1]=grid[0][0];

        if(m<1 or n<1 )return INT_MAX;

        if(dp[m-1][n-1]!=INT_MAX) return dp[m-1][n-1];

        return(dp[m-1][n-1]=min(rec(m-1,n,grid,dp),rec(m,n-1,grid,dp))+grid[m-1][n-1]);
  
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(205,vector<int>(205,INT_MAX));
        return rec(m,n,grid,dp);
    }
};


int main(){

vector<vector<int>>v{{1,2,3},{4,5,6}};
Solution s;
cout<<s.minPathSum(v);

}