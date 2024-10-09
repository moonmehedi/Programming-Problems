#include<bits/stdc++.h>
using namespace std;
//you have to declear y elese it may declear an error at line 11
class y;
class x{
    public:
    int data;
    x(int val){
        data=val;
    }  
    //this funciton is now a friend function of class x 
    friend int add(x a,y b);
    friend void swap(x &o1,y &o2);
};
class y{
    public:
    int data;
    y(int val){
        data=val;
    }
    //this function is now a friend funtion of class y
    friend int add(x a,y b);
    friend void swap(x &o1,y &o2);
};
/*accessing two data type from class x and y as argument*/
int add(x a,y b){
    return(a.data+b.data);
}
//this function swaps data
void swap(x &o1,y &o2){
    int temp=o1.data;
    o1.data=o2.data;
    o2.data=temp;
}
int main(){
    x variable1(22);
    y variable2(5);
    cout<<"adding data of x and y"<<endl;
    cout<<add(variable1,variable2);
    cout<<"after swapping data"<<endl;
    swap(variable1,variable2);
    cout<<variable1.data<<endl;
    cout<<variable2.data<<endl;
return 0;}