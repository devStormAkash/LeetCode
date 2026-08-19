#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    bool helper(int idx , int n , vector<int>& nums){
        if(idx>=n-1){
            return idx == n-1;
        }

        if(dp[idx]!=-1) return dp[idx];

        for(int i = 1 ; i <= nums[idx] ; i++){
            if(idx+i<n && helper(idx+i,n,nums)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,-1);
        return helper(0,n,nums);
    }
};