#include<bits/stdc++.h>
using namespace std;
void print(int arr[],int key,int n)
{
    for(int i=0;i<n;i++){
        if(key==i)
        cout<<endl;
        cout<<arr[i];
    }
}
int main(){
    int leftsum=0,rightsum=0,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        leftsum=leftsum+arr[i];
    }
    for(int i=0;i<n;i++){
        rightsum=rightsum+arr[i];
        leftsum=leftsum-arr[i];
        if(leftsum==rightsum){
        print(arr,i+1,n);return 0;}
    }
    cout<<"not possible";

}