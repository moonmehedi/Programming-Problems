#include<bits/stdc++.h>
using namespace std;
 /*********************FIRST OCCURANCE***************/
int first(int arr[],int k,int i,int key)
{
    if(arr[i]==key)
    return i;
    if(i==k-1)
    return 0;
    return first(arr,k,i+1,key);
}
/*****************LAST OCCURANCE**************/
int last(int arr[],int k, int i,int key)
{
    if(arr[i]==key)
    return i;
    if(i==0)
    return 0;
    return last(arr,k,i-1,key);}

/**************************IS THE ARRAY SORTED**********************/
int is_sorted(int arr[],int n,int k)
{
    if(n==k-1)
    return 1;
    if(arr[n]>arr[n+1])
    return 0;
    return is_sorted(arr,n+1,k);
}
int main()
{
   int arr[20],n=0,k;
   cout<<"size of array ";
   cin>>k;
   for(int i=0;i<k;i++)
   cin>>arr[i];
    int f=is_sorted(arr,n,k);
    if(f==0)
    cout<<"sorted not"<<endl;
    if(f==1)
    cout<<"sorted"<<endl;
   cout<<"*************************CODE FOR FIRST & LAST OCCURANCE********"<<endl;
   int key,i=0;
   cout<<"key number "<<endl;
   cin>>key;
    cout<<"first occurance "<<first(arr,k,i,key)<<endl;
    cout<<"last occurance "<<last(arr,k,k-1,key)<<endl;
}