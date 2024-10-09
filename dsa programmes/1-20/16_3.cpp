#include<bits/stdc++.h>
using namespace std;

/*PIRNTS A STRING IN REVERSE ORDER*/
void rev(string arr,int i)
{
    if(arr[i]=='\0')
      return ;
    rev(arr,i+1);
    cout<<arr[i];

}
int main()
{
    //REVERSE
    string arr;
    cin>>arr;
    rev(arr,0);
    //*****************REPLACE PI WITH 3.14*******
    cout<<"+++++++++++REPLACE PROGRAM+++++++++++++++\nINPUT STRING"<<endl;
    string pi;
    cin>>pi;


}