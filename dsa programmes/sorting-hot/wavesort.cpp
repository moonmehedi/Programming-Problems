#include<bits/stdc++.h>
using namespace std;
int main(){
  int n=7,arr[7]={1,3,4,7,5,6,2};
    for(int i=1;i<n;i+=2){
        /*making sure the element in the middle is smaller*/
        if((arr[i]>arr[i-1]))
        swap(arr[i],arr[i-1]);
        if((arr[i]>arr[i+1])&&i<=n-2)
        swap(arr[i],arr[i+1]);
    }
    for (int i=0;i<n;i++){
        cout<<arr[i];
    }

}