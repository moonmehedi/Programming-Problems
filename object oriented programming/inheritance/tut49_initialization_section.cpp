#include<bits/stdc++.h>
using namespace std;
/*
syntrx for initialization list in constructor;
constructor(arguments-list):initialization-section
{
    assigment+other code;
}
*/
class test
{
    public:
    int a ;
    int b ;
    public:
    //test(int i,int j):a(i),b(j)
    // test(int i,int j):a(i),b(i+j)
    // test(int i,int j):a(i),b(a+j)
    // test(int i,int j):a(i),b(2*j)
    // test(int i,int j):b(j),a(i+b)---->will show garbadge here we write a first thats why a will initial first
    //a should initial first
    test(int i,int j):a(i),b(3)//"3" will be given to b
    {
        cout<<"constructor is executed "<<endl;
        cout<<"value of a is "<<a<<endl;
        cout<<"value of b is "<<b<<endl;

    };
};
int main(){
    test moon(12,55);
    cout<<moon.b<<endl;
return 0;}