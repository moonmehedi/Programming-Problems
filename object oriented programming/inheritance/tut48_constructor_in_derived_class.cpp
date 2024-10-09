#include <bits/stdc++.h>
using namespace std;
/*case 1:
class B: public A{
    //here first constructor of public A will be called then constructor of public b be called
}
/*
case 3:
class A:public B,public C{
//here constructor of A will be called then constructor of B and at last constructor of C
}
*/
/*
case 3:
class A:public B,virtual public C{
  here C then B then A will be called
}
*/
class base1
{
public:
    int data1;
    base1(int a)
    {
        data1 = a;
        cout << "base1 constructor is called :" << endl;
    }
    void print_data1()
    {
        cout << "data stored in base class 1 :" << data1 << endl;
    }
};
class base2
{
public:
    int data2;
    base2(int a)
    {
        data2 = a;
        cout << "base2 constructor is called :" << endl;
    }
    void print_data2()
    {
        cout << "data stored in base class 2 :" << data2 << endl;
    }
};

// SEQUENCE OF CALL BASE2,BASE1,DERIVED BECAUSE OF VIRTUE FUNCTION
class derived : public base1, virtual public base2
{
    int data3, data4;

public:
    /*INPUTTING DATA TO BASE CLASS USING ONLY THE DERIVED CLASS*/
    derived(int a, int b, int c, int d) : base1(a), base2(b)
    {
        data3 = c;
        data4 = d;
        cout << "derived class constructor is called :" << endl;
    }
    void print_data3_data4(void)
    {
        cout << "the value of data3 is :" << data3 << endl;
        cout << "the value of data4 is :" << data4 << endl;
    }
};
int main()
{
    /*using derived class constructor to input data to all class*/
    derived moon(12, 13, 14, 15);
    moon.print_data1();
    moon.print_data2();
    moon.print_data3_data4();

    return 0;
}