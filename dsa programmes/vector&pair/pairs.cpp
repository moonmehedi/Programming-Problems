#include<bits/stdc++.h>
using namespace std; 
void print_pair(pair<int ,int>arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i].first<<arr[i].second<<endl;
    }
}
int main(){
                                                    /*THREE DIFFERENT METHODE TO DECLEAR A PAIR*/
    pair<int ,char>PAIR1;
    PAIR1.first=1;
    PAIR1.second='h';
    cout<<PAIR1.first<<endl;
    cout<<PAIR1.second<<endl;
    pair<int ,char>PAIR2(19,'h');
    cout<<PAIR2.first<<endl;
    cout<<PAIR2.second<<endl;
    pair<int ,char>PAIR3;
    PAIR3=make_pair(22,'h');
    cout<<PAIR3.first<<endl;
    cout<<PAIR3.second<<endl;
                                                 /*COPYING TWO PAIRS*/
pair<int,string>moon,mehedi,hasan;
moon=make_pair(21,"moon");
hasan.first=21;
hasan.second="hasan";
//COPYS ELEMENTS OF HASAN IN MEHEDI TIME COMPLEXITY 0(N)
mehedi=hasan;
cout<<mehedi.first<<hasan.first<<endl;
hasan.first=22;
cout<<mehedi.first<<hasan.first<<endl;
//HERE WE ARE NOT COPYING ELSE SENDING REFERENCE COMPLEXITY O(0)
pair<int,string> &mehed=moon;
cout<<mehed.first<<moon.first<<endl;
moon.first=22;
cout<<mehed.first<<moon.first<<endl;
                                                 /*DECLEARING ARRAY OF POINTERS*/
pair<int,int>arr[4];
arr[0]={1,2};
arr[1]={2,3};
//empty element is initialized with zero
arr[3]={3,4};
                                                 /*PRINT PAIR*/
print_pair(arr,4);

                                                 /**/
    
}