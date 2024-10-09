#include<bits/stdc++.h>
using namespace std;
/*THIS FUNCTION SORTS STRING IN DECREASIGN ORDER*/
void SORT(){
    string s="12345678g9";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
    
}
/*this function converts upper to lower case and lower to upper case*/
void TOUPPER(){
    string s="hello dear moon!";
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s<<endl;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s<<endl;
    //time complexity o(n)
}
int main(){
    cout<<"this function converts upper to lower case and lower to upper case"<<endl;
    TOUPPER();
    /*THIS FUNCTION SORTS STRING IN DECREASIGN ORDER*/
    cout<<"THIS FUNCTION SORTS STRING IN DECREASIGN ORDER"<<endl;
    SORT();
}