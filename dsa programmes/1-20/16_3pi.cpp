#include<bits/stdc++.h>
using  namespace std;
/*replace pi with 3.14*/
void pi(string s,int i)
{
    if(s[i]=='\0')return ;
    if(s[i]=='p'&&s[i+1]=='i')
    {cout<<"3.14";i+=2;}
    else{
        cout<<s[i];
        i++;
    }
    pi(s,i);
}
int main()
{
    string s;
    cin>>s;
    pi(s,0);
}