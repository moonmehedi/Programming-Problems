#include<bits/stdc++.h>
using namespace std;
string dublicate(string s ,string ans){
if(s.length()==1)
return ans+s[0];
if(s[0]!=s[1])
ans=ans+s[0];
return dublicate(s.substr(1),ans);
}
int main(){
    string s="aaaabbbbccccdddd";
    string ans="";
    cout<<dublicate(s,ans);

}