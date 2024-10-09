#include<bits/stdc++.h>
using namespace std;
                                        //function overloading
class moon{
    public:

    void fun(){
        cout<<"funciton with no argument is called"<<endl;
    }

    void fun(int n){
        cout<<"funciton with int argument is called"<<endl;
    }

    void fun(double a){
        cout<<"funciton with double argument is called"<<endl;
    }
};
                                         /*OPRATOR OVERLOAIDNG*/
class complexnumber{
    private:
    int real;
    int img;
    public:
    /*default constructor*/
    complexnumber(){}
    /*parametarized constructor*/
    complexnumber(int r,int i){
        real=r;
        img=i;
    }
                                    /*overloading the operator*/
    complexnumber operator + (complexnumber  &c3){
        complexnumber result;
        result.real=real+c3.real;
        result.img=img+c3.img;
        return result;
    }
    void print(){
        cout<<real<<"+i"<<img<<endl;}
};
                                /*FUNCITON OVERWRITING*/
class base{
    public;
    virtual void fun(){
        cout<<"this is base class function"<<endl;
    }

};
class derrived:base{
     void fun(){
        cout<<"this is class function"<<endl;
     }
}
int main(){
    /*example of function overloading*/
    moon a;
    a.fun();
    a.fun(4);
    a.fun(3.2);
    /*example of operator overloading*/
    complexnumber f(12,3),b(12,23);
    complexnumber c=f+b;
    c.print();
                            /*example of funtion over writing*/

}