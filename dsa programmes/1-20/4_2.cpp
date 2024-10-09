#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=9;
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<i;j++)
        cout<<" ";
        for(int m=0;m<n;m++)
        cout<<"x";
        cout<<endl;
    }


    for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
    {
        if((i%2)==0)
        cout<<(j+1)%2;
        if(i%2==1)
        cout<<j%2;
    }cout <<endl;}

    for(int i=n;i>0;i--)
    {
        for(int j=0;j<i;j++)
        cout<<" ";
        for(int k=1;k<=(n+1)-i;k++)
        cout<<" "<<k;
        cout<<endl;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>0;j--)
        {
            if(j<=i)
                cout<<j;
            else
            cout<<" ";
        }for(int j=2;j<=i;j++){
            cout<<j;
        }cout<<endl;
    }
/*START PATTER*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<n+i;j++){
            if(j>n-i) cout<<"*";
            else cout<<" ";
        }cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<2*n+1-i;j++){
            if(j>=i) cout<<"*";
            else cout<<" ";
        }cout<<endl;
    }

    /*this pattern is valid for n=9*/
    for(int i=1;i<=n/3;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%4==0||(i%2==0&&j%4==0)) cout<<"*";
            else cout<<" ";
        }cout<<endl;
    }

}