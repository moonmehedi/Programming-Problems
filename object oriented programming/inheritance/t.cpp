#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v(100,vector<int>(200,-1));

int main(){

    for(int i=0;i<100;i++){
        for(int j=0;j<200;j++){
            v[i][j]=(i*10+j*10);
        }
    }
    
}