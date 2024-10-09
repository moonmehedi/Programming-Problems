#include<bits/stdc++.h>
using namespace std;
void fun(int (*arr)[2],int n){
    arr[1][1]=10;
    //cout<<arr[2]<<endl;
}
int main()
{
    int arr[2][2]={{1,2},
                   {3,4}};
    cout<<arr[1][1]<<endl;
    fun(arr,5);
    cout<<arr[1][1]<<endl;

}