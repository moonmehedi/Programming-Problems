#include<bits/stdc++.h>
using namespace std;

     vector<vector<int>>dp(101,vector<int>(100));
class Solution {
public:

    int rec(int m,int n){
        if(m==1 and n==1) return dp[1][1]=1;
        if(m<1 or n<1 )return 0;

        if(dp[m][n]!=0) return dp[m][n];

        return( dp[m][n]=(rec(m-1,n)+rec(m,n-1)));
    }


    int uniquePaths(int m, int n) {
        dp.assign(m+1,vector<int>(n+1,0));
        return rec(m,n);
    }

};

int main(){

    Solution s;
    cout<<s.uniquePaths(7,3);



}