#include<bits/stdc++.h>
using namespace std;
/*this code prints all the prime factorisation of a number*/
void prime_factorisation(int arr[],int n){
    /*initializing with index value*/
    for(int i=2;i<=n;i++){
        arr[i]=i;
    }
    /*store small prime factor*/
    for(int i=2;i*i<=n;i++){
        if(arr[i]==i)
        for(int j=i*i;j<=n;j+=i){
            if(arr[j]==j)
            arr[j]=i;
        }
    }
    /*prints prime factors*/
    while(n!=1){
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }


}
/*this code prints prime number till n value*/
void sieve_0f_erathosthenes(int arr[],int n){
    for(int i=2;i*i<=n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<=n;j+=i)
            {
                if(arr[j]==0)
                arr[j]=1;
            }
        }
    }

    for(int i=2;i<n;i++){
        if(arr[i]==0)
        cout<<i<<" ";
    }
    cout<<endl;

}

int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    sieve_0f_erathosthenes(arr,n);
    prime_factorisation( arr, n);

}