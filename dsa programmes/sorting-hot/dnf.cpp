#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;                                                   /*FOR SORTING ARRAYS WITH THREE ELEMENTS*/
    int arr[n],low=0,high=n-1,mid=0;
   
    for(int i=0;i<n;i++){
        cin>>arr[i];
   }
    while(mid<=high){
        //IF ARR[MID] IS "0"THEN SWAP IT TO THE LEFT
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;low++;
        }
        //IF "1" STAY IT IN THE MID
        else if(arr[mid]==1){
            mid++;
        }
        //IF "2" SWAP TO THE RIGHT
        else{
            swap(arr[mid],arr[high]);
            high--;
        }}
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}