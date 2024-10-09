#include <bits/stdc++.h>
using namespace std;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)

#define int long long // define int as a long long data type
#define endl '\n'
int rotation_count(vector<int> &hasan){
    int high=hasan.size()-1;
    int low=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(!hasan[mid]<hasan[mid+1])
        return mid;
        else if(hasan[mid]<hasan[low]){
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return 0;

}

signed main()
{
    fast_io(); // enable faster I/O
    vector<int>v;
    int n;
    cin>>n;
    cout<<"enter array elements "<<endl;


    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
   int number_of_rotation=rotation_count(v);
    cout<<number_of_rotation;

    return 0;
}