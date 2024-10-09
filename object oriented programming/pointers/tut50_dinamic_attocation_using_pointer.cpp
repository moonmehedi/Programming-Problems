#include<bits/stdc++.h>
using namespace std;
int main(){
    //basic example
    int a=4;
    int *ptr=&a;
    cout<<"the value of ptr is  "<<*ptr<<endl;
    cout<<"address ptr indicate is "<<ptr<<endl;
    cout<<"the value of a is a "<<a<<endl;

    /*DYNAMIC ALLOCATION OF MEMORY*/
    //NEW KEYWORD
    int *p=new int(40);//here i have created a dynamic integer which value is 40:
    cout<<"value at address p is: "<<*p<<" location of p is :"<<p<<endl;

    /*ALLOCATING A BLOCK OF MEMORY TO STORE 4 INTEGERS*/
    int *arr=new int [3];//{allocating 3 size dynamic array;}
    arr[0]=10;
    *(arr+1)=20;
    arr[2]=30;
    //delete arr;
    cout<<"the value of arr[0] "<<arr[0]<<"and location : "<<arr<<endl;
    cout<<"the value of arr[1] "<<arr[1]<<"and location : "<<arr+1<<endl;
    cout<<"the value of arr[2] "<<arr[2]<<"and location : "<<arr+2<<endl;




return 0;}