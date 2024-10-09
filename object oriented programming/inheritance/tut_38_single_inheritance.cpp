#include <bits/stdc++.h>
using namespace std;
class base
{
    //only function of this class can access them
    int data1;

public:
    int data2;
    /*this function sets data*/
    void set_data()
    {
        data1 = 10;
        data2 = 15;
    }
    int get_data1()
    {
        return data1;
    }
};
/*derived class from base class*/
class derived : public base
{
    /*private data element*/
    //only fucntion of this class can access them
    int data3;

public:
    void process_data()
    {
        /*as data one is private attributes of the class base only base function can access them*/
        data3 = data2 * get_data1();
    }
    void display()
    {
        cout << "value of data 1 is " << get_data1() << endl;
        cout << "value of data 2 is " << data2 << endl;
        cout << "value of data 3 is " << data3 << endl;
    }
};
int main()
{
    derived a, b, c;
    a.set_data();
    a.process_data();
    a.display();

    return 0;
}