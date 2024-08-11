     vector<vector<int>>dp(205,vector<int>(205,1000000000));
class Solution {
public:

    int rec(int m,int n,vector<vector<int>>&grid){

        if(m==1 and n==1) return dp[m-1][n-1]=grid[0][0];

        if(m<=1 or n<=1 )return 1000000000;

        if(dp[m-1][n-1]!=1000000000) return dp[m-1][n-1];

        return(dp[m-1][n-1]=min(rec(m-1,n,grid),rec(m,n-1,grid))+grid[m-1][n-1]);
  
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        return rec(m,n,grid);
    }
};