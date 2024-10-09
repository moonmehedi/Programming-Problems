#include<bits/stdc++.h>
using namespace std;
/*this code update bit at a particular place*/
/*UPDATE BIT= CLEAR BIT + SET BIT*/
void update_bit(int n,int pos){
    n=(n^(1<<pos));
    cout<<(n|(1<<pos));
}
/*this code clear bit at a position*/
void clear_bit(int n,int pos){
    cout<<(n^(1<<pos))<<endl;
}
/*this function set a bit at a particular position*/
void set_bit(int n ,int pos){
    cout<<(n|(1<<pos))<<endl;
}
/*this function prints the bit at a position*/
int get_bit(int n,int pos){
    return((n&(1<<pos))!=0);
}
int main(){
int n,pos;
cin>>n>>pos;
cout<<get_bit(n,pos)<<endl;
set_bit(n,pos);
clear_bit(n,pos);
update_bit(n,pos);

}