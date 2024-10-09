#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

int bs(int key,int arr[],int n,bool t){
    int start=0;
    int stop=n-1;
    int result=-1;
    while(start<=stop){
        int mid=(start+stop)/2;
        if(arr[mid]<=key){
            start=mid+1;
            result =mid;
        }
        else{
            stop=mid-1;
        }
    }
    return result;
}

signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<":"<<endl;
        int n,q;
        cin>>n>>q;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<q;i++){
            int low,up;
            cin>>low>>up;
            int idx_low=bs(low,arr,n,true);
            if(arr[idx_low]!=low ){
                idx_low++;
            }
            int idx_up=bs(up,arr,n,false);
            cout<<idx_up-idx_low+1<<endl;
        }
    }
}