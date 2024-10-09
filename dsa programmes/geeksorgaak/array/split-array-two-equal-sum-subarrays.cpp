#include<bits/stdc++.h>
using namespace std;
int sum(int arr[],int start,int stop){
    int s=0;
    for(int j=start;j<=stop;j++){
        s=s+arr[j];}
        return s;
        
}
int Sum(int arr[],int start,int stop){
    int s=0;
    for(int j=start;j>stop;j--){
        s=s+arr[j];}
   return s;
}

int main(){
    int arr[30],n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(sum(arr,0,i)==Sum(arr,n-1,i))
        {
            cout<<"{";
            for(int j=0;j<=i;j++){
                cout<<arr[j];
            }cout<<"}"<<endl;
            cout<<"{";
            for(int j=i+1;j<n;j++){
                cout<<arr[j];
            }cout<<"}"<<endl;
             
             return 0;
        }
    }
    cout<<"not possible";
}