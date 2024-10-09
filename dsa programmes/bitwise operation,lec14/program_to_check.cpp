#include<bits/stdc++.h>
using namespace std;
/*checks number of one in a function*/
void number_of_one(int n){
    int s=0;
    for(int i=n;i!=0;i=i&i-1){
        s++;
    }
    cout<<s<<endl;
}
/*checks if a number is power of two*/
bool is_power_2(int n){
    return !(n&(n-1));
}
int main(){
    int n;
    cin>>n;
    cout<<is_power_2(n)<<endl;
    number_of_one(n);
}