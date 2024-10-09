#include<bits/stdc++.h>
using namespace std;


/*this algo takes most value elements*/
class iteam_detail{
    public:
    int value;
    int weight;
    int per_val;

    iteam_detail(){
        cout<<"iteam detail"<<endl;
        cin>>value;
        cin>>weight;
        per_val=value/weight;
    }

};

   bool mycomp(iteam_detail &a,iteam_detail &b){
    return a.per_val>b.per_val;
    }

int main(){

    int iteam_number,capacity;
    cin>>iteam_number>>capacity;
    vector<iteam_detail>v(iteam_number);

    sort(v.begin(),v.end(),mycomp);//sort according to per _value most value iteam will be taken first

    vector<int>ans;//store the prices

    int i=0;//loop running 
   // int w=INT_MAX;
    while(true){

        if(capacity-v[i].weight>0){//if capacity is larger
            capacity=capacity-v[i].weight;//take full iteam
            ans.push_back(v[i].value);//push value of iteam in vector
            i++;
        }
        else{//if capacity is smaller
            ans.push_back(v[i].per_val*capacity);//take iteam according to capacity and update the array
            break;
        }
   
    }

    vector<int>::iterator it;
    cout<<"iteams should be taken "<<endl;
    for(it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }


}