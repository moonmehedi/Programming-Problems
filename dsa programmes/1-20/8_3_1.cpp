#include<bits/stdc++.h>
using namespace std;
int main(){

    cout<<"*************SELECTION SHORTING***************"<<endl;
    int arr[]={9,8,7,6,5,4,3,2,1},n=9,s=0,m=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            m++;
            if(arr[i]>arr[j]){
                s++;
                int swap=arr[i];
                arr[i]=arr[j];
                arr[j]=swap;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }cout<<endl;
    cout<< "number of loop ="<<s<<endl<<"outer loop = "<<m<<endl;

cout<<"***************BUBBLE SORT************"<<endl;
int arr1[]={9,8,7,6,5,4,3,2,1};
s=0,m=0;
for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        m++;
        if(arr[j]<arr[j+1]){
            s++;
            int swap=arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=swap;
        }
    }
}
for(int i=0;i<n;i++){
    cout<<arr1[i];
}cout<<endl<<"number of loop ="<<s<<endl<<"outer loop = "<<m<<endl;

cout<<"**************INSERTAION SORT**********";
int arr3[]={9,8,7,6,5,4,3,2,1};
s=0;


cout<<"**************insertion sorting******";
int arr4[]={9,8,7,6,5,4,3,2,1};
s=0,m=0;
for(int i=1;i<n;i++){
    m++;
int key=arr4[i];
int j=i-1;
while(j>=0&&arr4[j]>key){
    s++;
    arr4[j+1]=arr4[j];
    j--;
}
arr4[j+1]=key;
}

for(int j=0;j<n;j++){
    cout<<arr4[j];
}

cout<<endl<<"loop = "<<endl<<s<<endl<<m;
}