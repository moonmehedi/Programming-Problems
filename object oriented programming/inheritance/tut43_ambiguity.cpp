#include<bits/stdc++.h>
using namespace std;

class base1{
    public:
    void greet(){
        cout<<"hello dear? "<<endl;
    }
};
class base2{
    public:
    void greet(){
        cout<<"kamon aso? "<<endl;
    }
};
class derived:public base1,public base2{
    public:
    string name;
    /*if my derived class also had a greet funtion then it would have been called
    ambiguity aumatic cleared
    unless i have to clear it myself*/
    void greeting_user(){
        cout<<name<<" ";
        /*here this code means we i call greet functio be half of a derived class
        object i then call greet funtion from base class two*/
        base2::greet();
    }
};
int main(){
    derived moon;
    moon.greeting_user();

return 0;}