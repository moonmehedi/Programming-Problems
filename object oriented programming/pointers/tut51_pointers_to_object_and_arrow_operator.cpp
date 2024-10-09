/*
using pointers for object is similar to using it for variable
*/
#include<bits/stdc++.h>
using namespace std;
class complex_number{
    public:
    int real,imaginary;
    void getdata(){
        cout<<"the real part is : "<<real<<endl;
        cout<<"the imaginary part is : "<<imaginary<<endl;
    }
    void setdata(int a,int b){
        real=a;
        imaginary=b;
    }

};
int main(){
    /*SUGGESTED*/
    //pointers can point towards an entire object and can called the objects class function through reference;
    complex_number var;
    complex_number *ptr=&var;//syntex is similar to typical varialble type pointer
    ptr->setdata(12,22);
    ptr->getdata();
    /*DYNAMIC ALLOCATIO*/
    //dynamic attocation using pointer is also the same
    complex_number *pointer= new complex_number;//dynamic memory allocation for a complex type object
    pointer->setdata(22,25);
    pointer->getdata();
    /*dynamic memory for object array*/
    complex_number *moon=new complex_number[4];
    /*defferent initilizationt*/
    moon->setdata(1,2);
    (moon+1)->setdata(2,3);
    (*(moon+2)).setdata(3,4);
    (moon+3)->setdata(4,5);

    moon->getdata();
    (moon+1)->getdata();
    (*(moon+2)).getdata();
    (moon+3)->getdata();

    // complex_number variable;
    // complex_number *p=&variable;
    // /*NOT SUGGESTED*/
    // (*p).setdata(12,13);//{writing *p.setdata(12,13) will generate error}
    // (*p).getdata();
return 0;}