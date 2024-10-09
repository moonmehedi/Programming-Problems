#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,result=0;
    cin>>n;
    for(int i=n;i!=0;i/=10)
    {
        int reminder=i%10;
        result=result+pow(reminder,3);
    }
    if(result==n)
    cout<<"armstrong number";
    else cout<<"not armstrong number";
}