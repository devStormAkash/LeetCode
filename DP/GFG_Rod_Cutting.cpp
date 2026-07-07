#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
// class Solution {
//   public:
//     ll fn(ll idx, ll wt,vector<int> &price,vector<vector<ll>>& dp){
//         if(idx == 0){
//             return wt*price[0];
//         }
        
//         if(dp[idx][wt]!=-1) return dp[idx][wt];
//         // take
//         ll take = LONG_MIN;
//         if(idx+1<=wt){
//             ll sub_ans = fn(idx,wt-idx-1,price,dp);
//             if(sub_ans!=LONG_MIN){
//                 take = price[idx]+sub_ans;
//             }
//         }
        
//         // not take
//         ll not_take = fn(idx-1,wt,price,dp);
        
//         return dp[idx][wt] = max(take,not_take);
        
//     }
    
//     int cutRod(vector<int> &price) {
//         ll n = price.size();
//         vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
//         return fn(n-1,n,price,dp);
        
//     }
// };



// Tabulation


// using ll = long long;
// class Solution {
//   public:
//     int cutRod(vector<int> &price) {
//         ll n = price.size();
//         vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
//         for(ll w = 0; w<=n; w++){
//             dp[0][w] = w*price[0];
//         }
        
//         for(ll idx =1; idx<n; idx++){
//             for(ll wt = 0;wt<=n; wt++){
//                 // take
//                 ll take = LONG_MIN;
//                 if(idx+1<=wt){
//                     ll sub_ans = dp[idx][wt-idx-1];
//                     if(sub_ans!=LONG_MIN){
//                         take = price[idx]+sub_ans;
//                     }
//                 }
                
//                 // not take
//                 ll not_take = dp[idx-1][wt];
                
//                 dp[idx][wt] = max(take,not_take);
//             }
//         }
//         return dp[n-1][n];
        
//     }
// };




// Space Optimization

using ll = long long;
class Solution {
  public:
    int cutRod(vector<int> &price) {
        ll n = price.size();
        vector<ll> prev(n+1,-1);
        for(ll w = 0; w<=n; w++){
            prev[w] = w*price[0];
        }
        
        for(ll idx =1; idx<n; idx++){
            vector<ll> curr(n+1);
            for(ll wt = 0;wt<=n; wt++){
                // take
                ll take = LONG_MIN;
                if(idx+1<=wt){
                    ll sub_ans = curr[wt-idx-1];
                    if(sub_ans!=LONG_MIN){
                        take = price[idx]+sub_ans;
                    }
                }
                
                // not take
                ll not_take = prev[wt];
                
                curr[wt] = max(take,not_take);
            }
            prev=curr;
        }
        return prev[n];
        
    }
};