#include<bits/stdc++.h>
using namespace std;
//THIS PORGRAM SIMPLELY LEFT OR RIGHT SHIFT A CODE
void leftright(int a)
{
    //left shift
    cout<<(a<<1)<<endl;
    //right shift
    cout<<(a>>1)<<endl;
}
int main(){
    int a=3;
    leftright(a);
}