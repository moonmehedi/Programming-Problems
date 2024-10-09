#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,max=-999999,in,sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            cin>>in;
            if(in>max)
            max=in;
        }
        sum=sum+max;
    }
    cout<<sum;
}