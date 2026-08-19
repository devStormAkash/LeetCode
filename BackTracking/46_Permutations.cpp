#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void helper(vector<bool>& flag,vector<vector<int>>& ans,vector<int>& ds ,vector<int>& nums)  {
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0 ; i<nums.size() ;i++){
            if(flag[i]) continue;
            flag[i] = true;
            ds.push_back(nums[i]);
            helper(flag,ans,ds,nums);
            ds.pop_back();
            flag[i] =false;
        }
    }  
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size());
        for(int i = 0 ; i<nums.size() ;i++){
            flag[i] = false;
        }
        vector<vector<int>> ans;
        vector<int> ds;
        helper(flag,ans,ds,nums);
        return ans;
    }
};