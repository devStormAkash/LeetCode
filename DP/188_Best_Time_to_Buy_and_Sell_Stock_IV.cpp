#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll dp[1001][2][101];
    ll fn(ll idx, bool can_buy , ll k, vector<int>& prices){
        if(k==0) return 0;
        if(idx>=prices.size()){
            if(k>=0) return 0;
            return -1e18;
        }

        if(dp[idx][can_buy][k]!=-1) return dp[idx][can_buy][k];
        if(can_buy){
            ll buy = -prices[idx]+fn(idx+1,0,k,prices);
            ll skip = fn(idx+1,1,k,prices);
            return dp[idx][can_buy][k] = max(buy,skip);
        }else{
            ll sell = prices[idx]+fn(idx+1,1,k-1,prices);
            ll skip = fn(idx+1,0,k,prices);
            return dp[idx][can_buy][k] = max(sell,skip);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fn(0,1,k,prices);
    }
};