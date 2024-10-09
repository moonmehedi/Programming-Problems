#include<bits/stdc++.h>
using namespace std;
                            /*entering binary number and checking it*/
class binary{
    string s;
    /*this funciton is private only class member can access them*/
    void check_binary();
    public:
    /*this function is defined outside*/
void read_binary();
void complement();
};

                                /*syntex of defining a function outside*/
void binary :: read_binary(){
cout<<"enter a binary number "<<endl;
cin>>s;
}
                                        /*function check binary*/
void binary :: check_binary(){
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'&&s[i]!='1'){
        cout<<"incorrect binary form"<<endl;
        return ;}
    }
    cout<<"correct binary form "<<endl;
}                                                  /*NESTING OF FUNTIONS*/
                                            /*function 1's complement*/
void binary :: complement(){
    cout<<"checking binary number"<<endl;
    /*this class funciton is accessed by another class fucntion complement()*/
    check_binary();
    cout<<"printing complement of the number"<<endl;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0')
        cout<<"1";
        else
        cout<<"0";
    }
    cout<<endl;
}


int main(){
    binary a;
    a.read_binary();
//    a.check_binary(); thia condition wont work as this function is private
    a.complement();
}