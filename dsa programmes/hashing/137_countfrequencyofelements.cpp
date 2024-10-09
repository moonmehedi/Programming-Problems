#include<bits/stdc++.h>
using namespace std;


//this code efficiently tells you about the frequency of a number
int main(){
    unordered_map<int,int>m;
    map<int,int>m1;
    
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int key;
        cout<<"enter number (means key)"<<endl;
        cin>>key;
        m[key]++;//increase the value for that number(initially all are 0)
        m1[key]++;}

    while (true){
        cout<<"enter number to check frequency  enter  -1 to stop"<<endl;
        int q;cin>>q;
        if(q==-1)
        break;
        cout<<m[q]<<endl;//output from unorder map
       
        //cout<<m1[q]<<endl;output ordered map

    }

    cout<<"the frequency would look like"<<endl;

    cout<<"ordered map"<<endl;
    map<int,int>::iterator it1;
    for(it1=m1.begin();it1!=m1.end();it1++){
        cout<<it1->first<<" "<<it1->second<<endl;
    }
    cout<<"unordered map"<<endl;
    unordered_map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }


    /*
    output of ordered map is ordered and output of unorderd map is unordered
    */

}
