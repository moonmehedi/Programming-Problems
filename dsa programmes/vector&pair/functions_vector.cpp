#include<bits/stdc++.h>
using namespace std;
void print_vector(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}
int main(){
    vector<int>moon,mehedi(6,7),hasan{1,2,3,4,5,6,7,8,9};//WE CAN DO STATIC INITIALIZATION
    int size;
    //number of elements
    cout<<"number of elements"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
       int element;
        cin>>element;
        moon.push_back(element);
    }
    print_vector(moon);
                                      /*INSERT()*/
    //it will automatic give me an iterator or
    //vector<int>::iterator it;
    auto it = mehedi.begin();
    mehedi.insert(it+3,4);
    print_vector(mehedi);
                                    /*EXAMPLE AT()*/
cout<<hasan.at(3)<<endl;
cout<<hasan[5]<<endl;



                                    /*EXAMPLE ERASE*/
it=hasan.begin();
hasan.erase(it+3);
//ELEMENT AT 4 INDEX HASBEEN ERASED
print_vector(hasan);


}