#include<bits/stdc++.h>
using namespace std;
/*factorial*/
int fac(int n){
    int s=1;
    for(int i=2;i<=n;i++)
    s*=i;
    return s;
}
/*pascal piramid*/
void pascal(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<fac(i)/(fac(j)*fac(i-j))<<" ";
        }cout<<endl;
    }

}
/*fibonacci*/
void fib(int n){
    int t1=0,t2=1;
    for(int i=1;i<=n;i++){
        cout<<t1;
       int s=t1+t2;
        t1=t2,t2=s;
    }return ;
}
/*prime number*/
int isprime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)
        return false;
    }
    return true;
}
int main()
{
    int a,b,n;
    cin>>a>>b;
    for(int a;a!=b;a++){
    if(isprime(a)==true)
    cout<<" "<<a<<endl;
    }

    cout<<"********************FIBONACCI*****************"<<endl;
    cout<<"enter number"<<endl;cin>>n;
    fib(n);
    cout<<"**********pascal pyramid************"<<endl;
    pascal(n);
}