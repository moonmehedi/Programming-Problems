#include<bits/stdc++.h>
using namespace std;
string x;
/*****************REPLACE X AT LAST**************/
void repx(string s,int i)
{
    if(s[i]=='\0'){
    cout<<x;return;}
    if(s[i]=='x')
    x=x+'x';
    else
    cout<<s[i];
    repx(s,i+1);

}
void dub(string s, int i)
{
    if(s[i]=='\0')
    return ;
    if(s[i]!=s[i+1])
    {
        cout<<s[i];
    }
    dub(s,i+1);
}
int main()
{
    string s,a;
    cin>>s;
    dub(s,0);
    cout<<endl;
    cout<<"/*******************REMOVEX*****************\nENTER STRING"<<endl;
    cin>>a;
    repx(a,0);


}
