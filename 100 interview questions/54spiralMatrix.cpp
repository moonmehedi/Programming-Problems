#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int low=0;int right=matrix[0].size()-1;
        int down=matrix.size()-1;

        vector<int>ans;
        if(down==0 )
        return matrix[0];
        else if(right==0){
            for(int i=0;i<=down;i++){
                ans.push_back(matrix[i][0]);
            }
            return ans;
        }


        while(low<=right and low<=down){


            //loop1
            int i=0;
            while(i<=right-low and low<=right){
                ans.push_back(matrix[low][low+i]);
                i++;
            }

            //loop2
            if(!(low<down)){
                break;
            }


             i=1;
             while(i<=down-low and low<=down){
                ans.push_back(matrix[low+i][right]);
                i++;
            }



            if(!(low<right)){
                break;
            }

            //loop3
              i=1;
             while(i<=right-low and low<right){
                ans.push_back(matrix[down][right-i]);
                i++;
            }

            //loop4
             i=1;
             while(i<=down-1-low and low<down){
                ans.push_back(matrix[down-i][low]);
                i++;
            }

            low++,right--,down--;
            //1,2,1
        }
        return ans;

    }
};



int main(){
    Solution s;
    vector<vector<int>>v{{1}};
    vector<int> ans =s.spiralOrder(v);

    for(auto ele:ans){
        cout<<ele<<" ";
    }
}