#include<bits/stdc++.h>
using namespace std;
class this_pinter{
    public:
    int a;
    /*this funciton returns a pointer type object of class this_pointer for that reason  return type is this_pointer*/
    this_pinter& set_data(int a){
        this->a=a;//this line means the a i am indicating is the a of the object for which the function is been called
        return *this;//this statement means i am returning an object of class this pointer
    }
    void get_data(){
        cout<<a<<endl;
    }
};
int main(){
    /*moon is a object of the class this pointer */
    this_pinter moon;
    /*moon*/
    moon.set_data(3).get_data();//as set_data will return an object i can use that object to call get_data

return 0;
}