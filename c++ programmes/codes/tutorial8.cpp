#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m=0,k=1,sum=0,Sum=0,f=0;
    cin>>n;
    for(k;k<=n;k++)
    {
        int i=1,j=n,a=1;
        while(true)
        {
           //int i=1,j=n;
           a++;
            if(i<=k)
            {
                sum+=i;
                i++;
            }
            if(j>=k)
            {
                Sum+=j;
                j--;
            }
            if(sum==Sum)
            {cout<<k;
            f=0;
            break;}
            if(a>=n)
            {
                f=1;
                break;
            }
        }
    }
    if(f==1)
    {
        cout<<"not pivot";
    }
}