#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,s,sum=0;
    cin>>n>>k>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i+k<n;i++){
        for(int j=i;j<i+k;j++)
        sum=sum+arr[j];
        if(sum==s)
        {
            cout<<"YES";
            for(int j=i;j<i+k;j++)
            cout<<arr[j];
            return 0;
        }sum=0;
    }
    cout<<"NO";

}