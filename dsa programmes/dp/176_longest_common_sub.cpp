#include<bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int lcs(int l1,int l2,string s1,string s2){
    if(l1==-1 or l2==-1)
    return 0;
    if(s1[l1]==s2[l2]){
        return 1+lcs(l1-1,l2-1,s1,s2);
    }
    else{
        dp[l1][l2]=max(dp[l1][l2],max(lcs(l1-1,l2,s1,s2),lcs(l1,l2-1,s1,s2)));
    }
    return dp[l1][l2];
}


int lcs_t(string s1,string s2){
    for(int i=0;i<2000;i++){
        dp[i][0]=0;
        dp[0][i]=0;
    }

    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++)[
            if(s[i]==s[j]){

            }
        ]
    }

}
int main(){
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            dp[i][j]=1;
        }
    }
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1.length()-1,s2.length()-1,s1,s2)<<endl;


    /*tabulatoin*/
    for(int i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
            dp[i][j]=1;
        }
    }
    cout<<lcs_t(s1.length()-1,s2.length()-1,s1,s2)<<endl;
}