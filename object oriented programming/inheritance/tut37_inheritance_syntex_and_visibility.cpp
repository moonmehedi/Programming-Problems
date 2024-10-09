#include <bits/stdc++.h>
using namespace std;
class employee
{
public:
    string name;
    int id;
    int salary = 35;
    employee() {}
    employee(string n, int i)
    {
        name = n;
        id = i;
        salary = 53;
    }
    void print()
    {
        cout << "name of employee " << name << endl
             << "id; " << id << endl
             << "salary; " << salary << endl;
    }
};
/*DERIVED CLASS SYNTEX
class{{derived-class-name}}:{{visibility mode}}{{base-class-name}}{
    class members/functions
}
*/
/*note
1/ default visibility mode is private
2/ private visibility mode: public members of the base class becomes private members to derived
3/private members of base class are nevered inherited
*/
// CREATING A DERIVED CLASS EMPLOYEE FROM THE BASE CLASS
class programmer : public employee
{ // this code means all public atributes are included in programmer class
public:
    int languagecode = 9;//you can set default value like this
    programmer() {}
    programmer(string n, int i)
    {
        /*as this class using data from base class ther must exits a default constructor
        to creater an object for derived class that stores its data*/
        name = n;
        id = i;
    }
};

int main()
{
    programmer skill("moon", 2);
    cout << skill.name << endl
         << skill.id << endl;
    cout << skill.languagecode << endl;

    return 0;
}