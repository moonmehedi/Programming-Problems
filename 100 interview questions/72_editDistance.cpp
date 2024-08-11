#include<bits/stdc++.h>
using namespace std;



vector<vector<int>>dp(1000,vector<int>(1000,-1));
class Solution {
public:

    int rec(int i,int j,string word1,string word2){
        if(i==0)
            return j;
        if(j==0)
            return i;

        if(dp[i][j]!=-1){
            return dp[i][j];

        }

        if(word1[i-1] == word2[j-1]){
            return dp[i][j]=rec(i-1,j-1,word1,word2);
        }
        return dp[i][j]= 1 + min(rec(i-1,j-1,word1,word2),min(rec(i-1,j,word1,word2),rec(i,j-1,word1,word2)));
    }

    int minDistance(string word1, string word2) {



        return rec(word1.length(),word2.length(),word1,word2);
        
    }
};