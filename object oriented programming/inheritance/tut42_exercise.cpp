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
    void greeting_user(){
        cout<<name<<" ";
        base2::greet();
    }
};
int main(){

return 0;}