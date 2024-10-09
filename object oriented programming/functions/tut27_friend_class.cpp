#include<bits/stdc++.h>
using namespace std;
/*it says complex_number class is decleared below*/
class complex_number;

class calculator{
    // int a;
    // int b;
    public:
    /*it says this functions are described below if we try to discribe them it will throw an error*/
    /*as this funciton may access the private attributes of the class complex_number 
    but in this state they dont even exits (causes error)
    //moreover this is not decleared as a friend function to the class complex_number
    thus it wont be able to access data (through error)*/
    int sumrealcomplex(complex_number o1,complex_number o2);
    int sumcompcomplex(complex_number o1,complex_number o2);
};
class complex_number{
    int a;
    int b;
    public:
    /*describing a class as friend class*/
    //this code means all the functions of the class calculator will be able to access data
    friend class calculator;
    void set_data(int val1,int val2){
        a=val1;
        b=val2;
    }
    void get_data(){
        cout<<"complex number "<<a<<"+i"<<b<<endl;
    }
};
/*here at the end delaring the friend fucntions*/
int calculator :: sumrealcomplex(complex_number o1,complex_number o2){
    return(o1.a+o2.a);
}
int calculator::sumcompcomplex(complex_number o1,complex_number o2){
    return ( o1.b+o2.b);
}
int main(){
    complex_number a,b;
    a.set_data(12,11);
    b.set_data(12,11);
    calculator result;
    /*we can only use the friend fucntion through a calculator type class*/
    int c=result.sumrealcomplex(a,b);
    cout<<c<<endl;
    int d=result.sumcompcomplex(a,b);
    cout<<d;

}