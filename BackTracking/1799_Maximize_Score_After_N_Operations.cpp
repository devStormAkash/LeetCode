#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<vector<bool>,int> mp;
    int helper(int ith,int n,vector<int>& nums,vector<bool>& vis){
        if(ith == n/2+1) return 0;
        if(mp.count(vis)) return mp[vis];
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(vis[i]) continue;
            for(int j = i+1 ; j<n ; j++){
                if(vis[j]) continue;
                vis[i]=1;
                vis[j]=1;
                ans = max(ans,ith*__gcd(nums[i],nums[j])+helper(ith+1,n,nums,vis));
                vis[i]=0;
                vis[j]=0;
            }
        }
        return mp[vis]=ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n,false);
        return helper(1,n,nums,vis);
    }
};

// Bitmask + DP

// class Solution {
// public:
//     vector<int> dp;
//     vector<int> nums;
//     int n;

//     int solve(int mask) {
//         if (mask == (1 << n) - 1)
//             return 0;

//         if (dp[mask] != -1)
//             return dp[mask];

//         int op = __builtin_popcount(mask) / 2 + 1;
//         int ans = 0;

//         for (int i = 0; i < n; i++) {
//             if (mask & (1 << i))
//                 continue;

//             for (int j = i + 1; j < n; j++) {
//                 if (mask & (1 << j))
//                     continue;

//                 int newMask = mask | (1 << i) | (1 << j);

//                 ans = max(
//                     ans,
//                     op * gcd(nums[i], nums[j]) +
//                     solve(newMask)
//                 );
//             }
//         }

//         return dp[mask] = ans;
//     }

//     int maxScore(vector<int>& nums) {
//         this->nums = nums;
//         n = nums.size();

//         dp.assign(1 << n, -1);

//         return solve(0);
//     }
// };