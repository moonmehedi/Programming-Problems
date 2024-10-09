#include<bits/stdc++.h>
using namespace std;
/*RECURSION*/
int fib(int n)
{
    if(n==0||n==1)
    return n;
    //if(n==1)
    //return 1;
    return fib(n-1)+fib(n-2);
}

 /********************POWER************/
    int power(int n,int p)
    {
        if(p==0)
        return 1;
        return n*power(n,p-1);
    }
/*summetion till n*/
    int sum(int n)
    {
        if(n==1)
        return 1 ;
        return n+sum(n-1);
    }
    int main()
    {
        int n,p;
        cin>>n>>p;
        cout<<"sum "<<sum(n)<<endl;
        cout<<"power "<<power(n,p)<<endl;
        cout<<"fibonacci "<<fib(n);
        //scanf("%d",&n);
        //printf("%d",sum(n));
    }


    