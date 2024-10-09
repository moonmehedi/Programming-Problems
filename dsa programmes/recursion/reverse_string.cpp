#include<bits/stdc++.h>
using namespace std;
void print(string s){
    if(s.length()==0) return ;
    print(s.substr(1));
    cout<<s[0];
}
int main(){
    string s="mehedi";
    print(s);
}