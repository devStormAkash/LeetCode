#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int n;
    int dp[1<<14];
    int dfs(int mask,vector<int>& nums1, vector<int>& nums2){
        if(mask == (1<<n)-1) return 0;
        
        if(dp[mask]!=-1) return dp[mask];
        
        int ans = INT_MAX;
        int arr2_element = __builtin_popcount(mask);
        for(int i = 0; i<n ; i++){
            if(mask&(1<<i)) continue;
            int new_mask = mask | (1<<i);
            ans = min(ans,(nums1[i]^nums2[arr2_element])+dfs(new_mask,nums1,nums2));
        }
        return dp[mask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
       n = nums1.size();
       memset(dp,-1,sizeof(dp)); 
       return dfs(0,nums1,nums2);
    }
};