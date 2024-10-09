#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    int data_base;
    base()
    {
        data_base = 1;
    }
    virtual void data()
    {
        cout << "base calss data :" << data_base << endl;
    }
};
class derived : public base
{
public:
    int data_derived;
    derived()
    {
        data_derived = 2;
    }
   // private:
    void data()
    {
        cout << "derived base class data " << data_base << endl;
        cout << "derived class data " << data_derived << endl;
    }

};
int main()
{
    base *ptr2 = new base;
    ptr2->data();
    base *ptr;
    derived derived_ob;
    ptr = &derived_ob;

    ptr->data(); // using virtual we have bind the base data() fun .now it will call derived data() fun
}