#include<bits/stdc++.h>
using namespace std;
//PRINTS FIRST REPEATING INDEX
int prints_first_repeating_index(int arr[],int n){
int repeat_index=INT_MAX,idx[n]={0},feq[n]={0};
for(int i=0;i<n;i++){
    feq[arr[i]]++;
    //FOR REPEATING INDEX THIS LOOP WILL BE TRUE AND STORES THE INDEX VALUE
    if(feq[arr[i]]>1&&repeat_index>idx[arr[i]])
    repeat_index=idx[arr[i]];
    //THIS LOOP STORES THE FIRST INDEX INFO FOR EVERY VALUE IN ARR[]
    else idx[arr[i]]=i;


}
if(repeat_index==INT_MAX)
return -1;
return repeat_index;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<prints_first_repeating_index(arr,n)<<endl;
}