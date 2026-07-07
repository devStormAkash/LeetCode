#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isPossible(int idx ,int non_empty_sets,int k , vector<int>& nums, vector<vector<int>> & path){
//         if(idx==nums.size()){
//             if(non_empty_sets != k) return false;
//             int x = accumulate(path[0].begin(),path[0].end(),0);
//             bool flag = true;
//             for(int i = 1 ; i<path.size() ; i++){
//                 int y = accumulate(path[i].begin(),path[i].end(),0);
//                 if(x != y){
//                     flag = false;
//                     break;
               
//                 }
//             }
//             return flag;
//         }
        
//         for(int i = 0 ; i<k ; i++){
//             if(path[i].size()>0){
//                 path[i].push_back(nums[idx]);
//                 if(isPossible(idx+1,non_empty_sets,k,nums,path)) return true;
//                 path[i].pop_back();
//             }
//             if(path[i].size()==0){
//                 path[i].push_back(nums[idx]);;
//                 if(isPossible(idx+1,non_empty_sets+1,k,nums,path)) return true;
//                 path[i].pop_back();
//                 break;
//             }
//         }

//         return false;

//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
        
//         vector<vector<int>> path(k); // total k subsets are possible , so create k buckets
//         return isPossible(0,0,k,nums,path);
//     }
// };

// Above code is giving tle

// class Solution {
// public:
//     bool isPossible(int idx ,int non_empty_sets,int k , vector<int>& nums, vector<int> & mask){
//         if(idx==nums.size()){
//             if(non_empty_sets != k) return false;
//             int sum = 0;
//             for(int i = 0; i<nums.size() ; i++){
//                 if((mask[0] & (1<<i)) != 0){
//                     sum+=nums[i];
//                 }
//             }
//             bool flag = true;
//             for(int i = 1; i<k ; i++){
//                 int s = 0;
//                 for(int j = 0; j<nums.size() ; j++){
//                     if((mask[i] & (1<<j)) != 0){
//                         s+=nums[j];
//                     }
//                 }
//                 if(s!=sum){
//                     flag = false;
//                     break;
//                 }
//             }

//             return flag;
//         }
        
//         for(int i = 0 ; i<k ; i++){
//             if(mask[i]>0){
//                 int temp = mask[i];
//                 mask[i] = mask[i] | 1<<idx;
//                 if(isPossible(idx+1,non_empty_sets,k,nums,mask)) return true;
//                 mask[i] = temp;
                
//             }
//             if(mask[i]==0){
//                 int temp = mask[i];
//                 mask[i] = mask[i] | 1<<idx;
//                 if(isPossible(idx+1,non_empty_sets+1,k,nums,mask)) return true;
//                 mask[i] = temp;
//                 break;
//             }
//         }

//         return false;

//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
        
//         vector<int> mask(k,0); // total k subsets are possible , so create k buckets
//         return isPossible(0,0,k,nums,mask);
//     }
// };

// Above is bitmsk apllication but with same recursion logic , so can't be passed, givung tle



// Ultimate solution By Bitmask + DP
class Solution {
public:
    int n;
    int sum;
    int dp[1<<16];

    bool isPossible(int mask,int currSum,vector<int>& nums){
        if(mask == (1<<n)-1) return currSum == 0;

        if(dp[mask]!=-1) return dp[mask];

        for(int i = 0; i<n ; i++){
            if(mask & (1<<i)) continue;
            int val = nums[i];
            if(val+currSum>sum) continue;
            int new_mask = mask|(1<<i);
            int new_currSum = (val+currSum)%sum;
            if(isPossible(new_mask,new_currSum,nums)) return dp[mask] = true;
        }
        return dp[mask] = false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%k) return false;
        sum = s/k;
        memset(dp,-1,sizeof(dp));
        return isPossible(0,0,nums);
    }
};