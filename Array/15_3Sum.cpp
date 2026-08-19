#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void two_sum(int l , int r, int target, vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        while(l<r){
            if(target==nums[l]+nums[r]){
                while(l<r && nums[l]==nums[l+1]){
                    l++;
                }
                while(l<r && nums[r]==nums[r-1]){
                    r--;
                }
                ans.push_back({nums[l],nums[r],-target});
                l++;
                r--;
            }else if(target>nums[l]+nums[r]){
                l++;
            }else{
                r--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        int n = nums.size();
        for(int i = 0; i<=n-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            if(nums[i]>0) break;    
            int target = -nums[i];
            two_sum(i+1,n-1,target,nums,ans);
        }
        return ans;
    }
};