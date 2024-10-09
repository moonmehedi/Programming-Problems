#include<bits/stdc++.h>
using namespace std;
class complex_num{
    public:
    int a;
    int b;

    void set_data(int val1,int val2){
        a=val1;
        b=val2;
    }
    void get_data(){
        cout<<"number is ";
        cout<<a<<"+i"<<b;
    }
    void convert_to_binary(complex_num num1,complex_num num2){
        a=num1.a+num2.a;
        b=num1.b+num2.b;
    }

};

int main(){
    complex_num c1,c2,c3;
    c1.set_data(12,12);
    c2.set_data(12,12);
    c3.convert_to_binary(c1,c2);
    c3.get_data();
}