#include<bits/stdc++.h>
using namespace std;
class shop{
    int iteamid[100];
    int price[100];
    int count;
    public:
    void initial_count(){ count=0;}
    void set_data();
    void get_data();
};
void shop :: set_data(){
    cout<<"enter iteam id"<<endl;
    cin>>iteamid[count];
    cout<<"enter price"<<endl;
    cin>>price[count];
    count++;
}
void shop::get_data(){
    for(int i=0;i<count;i++)
    cout<<"iteam id "<<iteamid[i]<<" product price is "<<price[i]<<endl;
}
int main(){
    /*as one dokan have multiple product*/
    shop dadu;
    dadu.initial_count();
    cout<<"enter number of point"<<endl;
    int n;
    cin>>n;
    /*setting three product data*/
    for (int i=0;i<n;i++){
    dadu.set_data();}
    dadu.get_data();

}