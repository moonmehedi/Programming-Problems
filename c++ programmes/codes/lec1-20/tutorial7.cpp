#include<bits/stdc++.h>  
using namespace std;
int c ='m';
int main()
{
    int c=20;
    cout<<"value of local c "<< c<<endl;
    // ::this is scope resulation operator used to indicate global variable
cout<<"the value of global c is "<<::endl;


                        /*type casting in c++*/

                        cout<<"the size of g is "<<sizeof(34.54)<<endl;//primarylity it will count as double if no sign
                        cout<<"the size of g is "<<sizeof(34.54f)<<endl;//cast as float you can write F as well
                        cout<<"the size of g is "<<sizeof(34.54l)<<endl;//cast as long 
                        cout<<"the size of g is "<<sizeof(34.54i)<<endl;//cast as int
                        cout<<"the size of g is "<<sizeof(34.54li)<<endl;
        /*******************************************REFERENCE**VARIABLE*******************************/
            //INITIAL IDEA OF POINTER
            int x=455;
            int &y=x;
            cout<<x<<endl;
            cout<<y<<endl; //HERE Y POINTES TO X 



            /*//////////////////////////TYPECASTING**********************************/
            int a=24;
            float b =35.55;
            cout<<"the vlue of b is   "<<(float)b<<endl;//    CAN BE WRITTEN AS a(float) same
            cout<<"the value of a is "<<float(a)<<endl;
                            /*OPERATION BETWEEN A,B*/
            cout<<"the value of int (a+b) "<<int(a+b)<<endl;
            cout<<"the value of a +inb(b) "<<a+int(b)<<endl;
            cout<<"the value of  float(a)+int(b) "<<float(a)+int(b)<<endl;
}               

                