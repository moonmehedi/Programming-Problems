#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
    vector<vector<int>> ans;

    void solve(vector<int>&nums,int l,int r){
        if(l==r){
            ans.push_back(nums);
            return;
        }

        for(int i=l;i<=r;i++){
            swap(nums[i],nums[l]);
            solve(nums,l+1,r);
            swap(nums[i],nums[l]);
        }

    }
        vector<vector<int>> permute(vector<int>& nums) {
        
        solve(nums,0,nums.size()-1);
        return ans;


    }


};