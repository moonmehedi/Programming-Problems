#include<bits/stdc++.h>
using namespace std;
class student{
    /*PRIVATE DATA ELEMENT*/
    string catagory;//can not be accessed out side class
    public:
    string name;
    int age;
    bool gender;

    /*getinfo*/
    void getinfo(){
       cin>>name;
       cin>>age;
       cin>>gender;
       cin>>catagory;
    }
    /*PRINT INFO*/
    void printinfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
        cout<<catagory<<endl;
    }

};
int main(){
    student a;
    a.name="moon";
    a.age=22;                                           
    a.gender=true;
    cout<<a.name<<endl;
    cout<<a.age<<endl;
    cout<<a.gender<<endl;
    int n;
    cout<<"number of elements"<<endl;
    cin>>n;
    student arr[n];
    for(int i=0;i<n;i++){                                                                                                                                   
        arr[i].getinfo();                                                                                                                               
    }                                                                                                                               

    for(int i=0;i<n;i++){                                                                                                                               
        arr[i].printinfo();}               

}