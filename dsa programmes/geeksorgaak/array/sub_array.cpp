#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int start =0;start<n;start++){
    for(int stop=start;stop<n;stop++){
    for(int i=start;i<=stop;i++)
    {cout<<arr[i];}
    cout<<endl;}}
}