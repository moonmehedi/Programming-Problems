#include<bits/stdc++.h>
using namespace std;

class base1
{
    protected:
    int base1int;
    public:
    void set_data_base1(int a){
base1int=a;
    }
};
class base2{
    protected:
    int base2int;
    public:
    void set_data_base2(int a){
        base2int=a;
    }
};
class base3{
    protected:
    int base3int;
    public:
    void set_data_base3(int a){
        base3int=a;
    }
};
/*code for multiple inheritance*/
class derived:public base1,public base2,public base3{
public:
    int moon=9;
void display(){
    cout<<"base1 value of base2int is :"<<base1int<<endl;
    cout<<"base2 value of base2int is :"<<base2int<<endl;
    cout<<"base3 value of base3int is :"<<base3int<<endl;
    cout<<"summetion of all the datas of all the base is "<<base1int+ base2int+base3int<<endl;
}
};
int main(){

    derived obj;
    /*accessing all the datas from base1,2,3 using a derived class object*/        
    obj.set_data_base1(1);
    obj.set_data_base2(2);
    obj.set_data_base3(3);
    obj.display();
    

return 0;}