#include<bits/stdc++.h>
using namespace std;
int main(){
int n,max=INT_MIN;
cin>>n;
int arr[n],f[100]={0};
//STEP1 INPUT ARRAY 
//FIND MAX ELEMENT
//FIND FREQUENCY ARRAY
for(int i=0;i<n;i++){
    cin>>arr[i];
    if(max<arr[i])
    max=arr[i];
    f[arr[i]]++;
}
//FIND POSTITION ARRAY IT STORES THE LAST OCCURING INDEX OF i;
//SIZE MAX+1;
int pos[max+1]={0},result[n];
for(int i=1;i<max+1;i++){
    //or you can make store frequency in position vector f[i]=f[i-1]+f[i]
pos[i]=pos[i-1]+f[i];
}
//MAKE RESULT ARRAY 
//TRAVERSE MAIN ARRAY FROM LAST INDEX 
//FOR EVERY ELEMENT ARR[i];POSITION ARRAY WILL INDICATE IT'S LAST OCCURING INDEX
//AT THAT INDEX PIT VALUE OF ARR[i]
//REDUCE POS ARRAY BY ONE NOW IT INDICATES THE SECOND LAST INDEX;
//THUS FILL THE RESULT ARRAY
for(int i=n-1;i>=0;i--){
    result[pos[arr[i]]-1]=arr[i];
    pos[arr[i]]--;
}
/*PRINT RESULT ARRAY*/
for(int i=0;i<n;i++){
   cout<<result[i];
}


}