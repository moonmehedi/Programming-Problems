#include<bits/stdc++.h>
using namespace std;
void longest_arithmatic_subarray();
int sum_of_array(int a[],int m);
int main(){
    /*SUB ARRAY */
int    arr[]={0,1,2,3,4,5,6,7,8,9},n=10,sum;
    for(int start=0;start<n;start++){//STARTING INDEX
    for(int stop=start;stop<n;stop++){//STOPING INDEX
        sum=0;
        cout<<"{";
        for(int j=start;j<=stop;j++){//PRINTS VALUE FROM START TO STOP
            cout<<arr[j];
            sum=sum+arr[j];
        }
        cout<<"}= "<<sum<<endl;
    }}
    sum_of_array(arr,n);
    longest_arithmatic_subarray();
}
//PRINTS ONLY THE SUM OF ALL SUB ARRAYS
int sum_of_array(int a[],int m){
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=i;j<m;j++){
            sum=sum+a[j];
            cout<<sum;
            if(i!=m-1)
            cout<<",";
        }
    }
cout<<endl;
}
//LONGEST ARITHMATIC SUBARRAY
void longest_arithmatic_subarray(){
    int s=2,m=2,n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int previous_difference=arr[0]-arr[1];
    for(int i=1;i<n-1;i++){
        int current_difference=arr[i]-arr[i+1];
        if(previous_difference==current_difference){
            s++;
            if(s>m)
            m=s;
        }else
        s=2;
        previous_difference=current_difference;
    }
    
cout<<m;  
}