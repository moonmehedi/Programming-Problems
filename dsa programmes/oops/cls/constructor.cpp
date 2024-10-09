#include<bits/stdc++.h>
using namespace std;
class student {                               /*this element is private only fuction of this class will access them*/
    string name;
    public:
    int age;
    char gender;                                              /*default constructor*/
    //constructor is called when we creat an element
    student(){
        cout<<"default constructor called"<<endl;
    }                                      /*as passing parameter this is parameterized constructors*/
    student (string s,int a,char g){
        cout<<"parameterized constructor called"<<endl;
        name=s;
        age=a;
        gender=g;
    }                                            /*copy constructor*/
    //we also have a default copy constructor 
    //but default copy constructor dont copy from address
    //deep copy constructor copy from addresses(copy and location both are copyed)
    student(student &c){
        cout<<"copy constructor is called"<<endl;
        name=c.name;
        age=c.age;
        gender=c.gender;
    }                                           /*destructor*/
//destructor is called when an object is destroyed
~student(){
    cout<<"destructor is called"<<endl;
}                                        /*operator overloading*/
//changing the behaviour of an operapor
bool operator ==(student &a){
    return (name==a.name&&age==a.age&&gender==a.gender);}
    /*prints info of an object */
    void printinfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;}
};
int main(){
    student a("moon",22,'m');
  /*printinfo for object a*/
    a.printinfo();
    student b("hasan",21,'m');
    student c=a;
    c.printinfo();
    if(c==b)
    cout<<"same"<<endl;
    else
    cout<<"not same"<<endl;



}