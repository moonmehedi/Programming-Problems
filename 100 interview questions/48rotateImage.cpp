#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int low=0,high=matrix[0].size()-1;

        int n=high;

        while(low<high){
            int i=0;
            
            while(i<=n-1){
            int top=matrix[low][low+i];
            matrix[low][low+i]=matrix[high-i][low];
            matrix[high-i][low]=matrix[high][high-i];
            matrix[high][high-i]=matrix[low+i][high];
            matrix[low+i][high]=top;

            i++;
            }
            low++,high--;
            n-=2;
        }


    }
};





int main(){
    Solution s;
    vector<vector<int>>v{{5,1,9,11,12},{2,4,8,13,10},{13,3,6,7},{15,14,12,16}};
    s.rotate(v);
    
}