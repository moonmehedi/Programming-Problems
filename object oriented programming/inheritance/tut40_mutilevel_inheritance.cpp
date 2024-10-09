#include <bits/stdc++.h>
using namespace std;
/*base class*/
class student
{
protected://protected attributes can be inherited
    string name;
    int roll;

public:
    void set_data(string n, int r)
    {
        name = n;
        roll = r;
    }
};
/*2nd derived class*/
class exam : public student//public attributes are public but protected are still protected
{
public:
    float math;              //name
    float physics;           //roll are protected data of this class
    void set_marks(float m1, float m2)
    {
        math = m1;
        physics = m2;
    }
    void get_marks()
    {
        cout << "your marks in math " << math << endl;
        cout << "yours marks in physics " << physics << endl;
    }
};
/*3rd derived class */
class result : public exam//
{public:
    float percentage;
    void display(){
        cout<<"student info"<<endl<<"name :"<<name<<endl<<"roll :"<<roll<<endl;
        get_marks();
        cout<<"your percentages :"<<(math+physics)/2<<endl;
    }
};

int main()
{
    result moon;
    /*here object moon can access the function and attributed of the student and exam class
    as it is derived from them */
    moon.set_data("mehedi",202214048);//function of student class
    moon.set_marks(99,100);//funciton of exam class
    moon.display();//funciton of result class

    return 0;
}