#include<bits/stdc++.h>
using namespace std;
class complex_number{
    int a;
    int b;
    public:
    /*declearation of friend functions*/
    friend complex_number sumcomplex(complex_number o1,complex_number o2);
    void set_data(int val1,int val2){
        a=val1;
        b=val2;
    }
    void get_data(){
        cout<<"complex number "<<a<<"+i"<<b<<endl;
    }
};
/*this function can access only a and b if it is a friend function of class complex_number*/
//with out that it wont access private attributes of the class complex_number.
complex_number sumcomplex(complex_number o1,complex_number o2){
    complex_number o3;
    o3.set_data((o1.a+o2.a),(o1.b+o2.b));
    return o3;
    
}
int main(){
    complex_number a,b,c;
    a.set_data(12,12);
    a.get_data();
    b.set_data(12,12);
    b.get_data();
    c=sumcomplex(a,b);
    c.get_data();
}
/*properties of friend functions*/
//not in the scope of class
//since it's not in the scope of the class it can not be called from the object of that class
//c1.sumComplex()==invalid
//