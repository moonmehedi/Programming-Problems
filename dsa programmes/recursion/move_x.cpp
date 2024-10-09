#include<bits/stdc++.h>
using namespace std;
string move_x(string s ,string ans,string x){
if(s.length()==0)return ans+x;
if(s[0]!='x')
ans=ans+s[0];
if(s[0]=='x'||s[0]=='X')
x=x+s[0];
return move_x(s.substr(1),ans,x);
}
int main(){
    string s="xaxxbxxcxxdx",x="",ans="";
    cout<<move_x(s,ans,x);

}