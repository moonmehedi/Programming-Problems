#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'

int b_s(int berry ,int arr[],int n){
    int start=0;
    int stop=n-1;
    int result=-1;
    while(start<=stop){
        int mid=(start+stop)/2;

        if(arr[mid]>=berry){
            result=mid;
            stop=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    return result;
}

signed main(){
    int n;cin>>n;
    int arr[n];
    cin>>arr[0];
    for(int i=1;i<n;i++){
        cin>>arr[i];
        arr[i]=arr[i]+arr[i-1];
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int berry;
        cin>>berry;
        cout<<b_s(berry,arr,n)+1<<endl;
    }
}