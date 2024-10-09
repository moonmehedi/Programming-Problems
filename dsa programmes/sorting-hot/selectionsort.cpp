#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
/*TAKE AN ELEMENT ARR[I]  COMPARE IT WITH REST OF THE ARRAY IF ARR[I] IS NOT SMALLER THAN AN ELEMENT 
ARR[J] ,SWAP
THSU FOR EVERY VALUE OF I WE WILL GET THE SMALLEST VAULE OF J 
*/
for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
        if(!(arr[i]<arr[j]))
        swap(arr[i],arr[j]);
for(int i=0;i<n;i++){
    cout<<arr[i];
}
}