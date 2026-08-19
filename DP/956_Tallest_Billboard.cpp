#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     unordered_map<string,bool> mp;
//     bool fn(int idx,int cnt ,int sum ,int target ,vector<int>& rods, int mask){
//         if(idx==rods.size()){
//             if(sum == 0){
//                 cnt--;
//                 if(cnt==0) return true;
//                 else return fn(0,cnt,target,target,rods,mask);
//             }else return false;
//         }

//         string s = to_string(idx)+'#'+to_string(cnt)+'#'+to_string(sum)+'#'+to_string(mask);
//         if(mp.count(s)) return mp[s];
//         // take
//         bool take = false;
//         if((mask&(1<<idx))==0){
//             int new_mask = mask|(1<<idx);
//             take = fn(idx+1,cnt,sum-rods[idx],target,rods,new_mask);
//         }

//         // skip
//         bool skip = fn(idx+1,cnt,sum,target,rods,mask);
//         return mp[s] = take || skip;
//     }

//     int tallestBillboard(vector<int>& rods) {
//         int n = rods.size();
        
//         int l = 1;
//         int r = accumulate(begin(rods),end(rods),0);
//         int ans = 0;

//         for(int i = r ; i>=l ; i--){
//             mp.clear();
//             if(fn(0,2,i,i,rods,0)){
//                 return i;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     unordered_map<int,unordered_map<int,unordered_map<int,int>>> mp;
//     int fn(int idx,int bkt1, int bkt2, vector<int>& rods){
//         if(idx==rods.size()){
//             if(bkt1==bkt2){
//                 return bkt1;
//             }else return INT_MIN;
//         }
//         if(mp[idx][bkt1].count(bkt2)) return mp[idx][bkt1][bkt2];
//         int take_in_bkt1 = fn(idx+1,bkt1+rods[idx],bkt2,rods);
//         int take_in_bkt2 = fn(idx+1,bkt1,bkt2+rods[idx],rods);
//         int skip = fn(idx+1,bkt1,bkt2,rods);

//         return mp[idx][bkt1][bkt2]=max({take_in_bkt1,take_in_bkt2,skip});
        
//     }

//     int tallestBillboard(vector<int>& rods) {
//         int n = rods.size();
//         int ans = fn(0,0,0,rods);
//         return ans;
//     }
// };

class Solution {
public:
    int dp[21][10002];
    int fn(int idx,int diff, vector<int>& rods){
        if(idx==rods.size()){
            if(diff==0){
                return 0;
            }else return INT_MIN;
        }
        if(dp[idx][diff+5000]!=-1) return dp[idx][diff+5000];

        int x = rods[idx];
        int take_in_bkt1 = rods[idx] + fn(idx+1,diff+x,rods);
        int take_in_bkt2 = rods[idx] + fn(idx+1,diff-x,rods);
        int skip = fn(idx+1,diff,rods);

        return dp[idx][diff+5000]=max({take_in_bkt1,take_in_bkt2,skip});
        
    }

    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        int n = rods.size();
        int ans = fn(0,0,rods);
        return ans/2;
    }
};
