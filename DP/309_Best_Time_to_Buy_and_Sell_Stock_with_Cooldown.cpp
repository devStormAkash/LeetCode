#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    ll dp[5001][2];
    ll fn(ll idx, bool can_buy , vector<int>& prices){
        if(idx>=prices.size()) return 0;
        if(dp[idx][can_buy]!=-1) return dp[idx][can_buy];
        if(can_buy){
            ll buy = -prices[idx]+fn(idx+1,0,prices);
            ll skip = fn(idx+1,1,prices);
            return dp[idx][can_buy] = max(buy,skip);
        }else{
            ll sell = prices[idx]+fn(idx+2,1,prices);
            ll skip = fn(idx+1,0,prices);
            return dp[idx][can_buy] = max(sell,skip);
        }

    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return fn(0,1,prices);
    }
};