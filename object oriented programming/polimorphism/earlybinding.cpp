#include <bits/stdc++.h>
using namespace std;
class base
{
public:
    int data_base;
    void data()
    {
        cout << "base calss data :" << data_base << endl;
    }
};
class derived : public base
{
public:
    int data_derived;
    void data()
    {
        cout << "derived base class data " << data_base << endl;
        cout << "derived class data " << data_derived << endl;
    }
};
int main()
{
    derived *derived_ob = new derived;
    derived_ob->data_base = 15;
    derived_ob->data_derived = 20;
    cout << "using derived pointer to access the data of both derived and base class " << endl;
    derived_ob->data();
    derived_ob->base::data();

    // early binding
    cout << "this is the example of earlybinding " << endl;

    base *ptr;
    // derived derived_ob2;

    // because of compiletime polymorphism the compiler will bind the pointer to its base class funtions
    // even though the ob is of derived class
    ptr = derived_ob;
    ptr->data_base = 10;
    ptr->data();
    // ptr->data_derived //provides error
}