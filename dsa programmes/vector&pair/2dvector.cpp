#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &v){
    for(int row=0;row<v.size();row++){
        for(int colum=0;colum<v[row].size();colum++){
           cout<<v[row][colum]<<" ";
    }cout<<endl;
        }
}
int main(){
    int a;
    vector<vector<int>> mehedi;
    for(int row=0;row<3;row++){
        /*make an 1d vector push back all coloum value for row i*/
        vector<int>rowvec;
        for(int colum=0;colum<3;colum++){
            cin>>a;
            rowvec.push_back(a);
        }mehedi.push_back(rowvec);//push back the row vector in the main vector
    }
    print(mehedi);
}