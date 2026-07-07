#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Recursion+Memoization

// using ll = long long;
// class Solution {
// public:

//     ll fn(ll idx,ll wt,vector<ll>& coins,vector<vector<ll>>& dp){
//         if(idx == 0){
//             if(wt!=0) return 1;
//             else return 1;
//         }
//         if(dp[idx][wt]!=-1) return dp[idx][wt];
//         // not take
//         ll not_take = 1*fn(idx-1,wt,coins,dp);
//         // take
//         ll take = LONG_MIN;
//         if(coins[idx]<=wt){
//             take = coins[idx]*fn(idx,wt-coins[idx],coins,dp);
//         }
//         return dp[idx][wt] = max(not_take,take);
//     }
//     int integerBreak(int n) {
//         vector<ll> coins;
//         for(ll i = 1; i<=n-1; i++){
//             coins.push_back(i);
//         }
//         vector<vector<ll>> dp(n-1,vector<ll>(n+1,-1));
//         return fn(n-2,n,coins,dp);
//     }
// };



// Tabulation
using ll = long long;
class Solution {
public:
    int integerBreak(int n) {
        vector<ll> coins;
        for(ll i = 1; i<=n-1; i++){
            coins.push_back(i);
        }
        vector<vector<ll>> dp(n-1,vector<ll>(n+1,-1));

        for(ll w = 0; w<=n; w++){
            dp[0][w]=1;
        }

        for(ll idx = 1; idx<n-1; idx++){
            for(ll wt = 0; wt<=n; wt++){
                // not take
                ll not_take = 1*dp[idx-1][wt];
                // take
                ll take = LONG_MIN;
                if(coins[idx]<=wt){
                    take = coins[idx]*dp[idx][wt-coins[idx]];
                }
                dp[idx][wt] = max(not_take,take);
            }
        }

        return dp[n-2][n];
    }
};