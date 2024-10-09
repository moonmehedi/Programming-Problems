#include<bits/stdc++.h>
using namespace std;
class shop{
    int id;
    float price;
    public:
    void setdata(int i,float p){
        cout<<"enter id and price "<<endl;
        id=i;
        price=p;
    }
    void getdata(){
        cout<<"id for the product is : "<<id<<endl;
        cout<<"price for the product is : "<<price<<endl;
    }
};
int main(){
            /*here i am using various memory element using pointer*/
    int size=3;
    shop *moon=new shop[size];
    for (int i=0; i < size; i++)
    {
        int p;float q;
        cout<<"enter serial NO :  "<<i+1<<endl;
        cin>>p>>q;
        (moon+i)->setdata(p,q);
    }

    /*print array data */
    for (int i=0 ; i < size; i++)
    {
        cout<<"serial NO : "<<i+1<<endl;
        (moon+i)->getdata();
    }
    
return 0;}