#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll dp[50001][2];
    ll fn(ll idx , bool can_buy, ll fee, vector<int>& prices){
        if(idx>=prices.size()) return 0;
        if(dp[idx][can_buy]!=-1) return dp[idx][can_buy];
        
        if(can_buy){
            ll buy = -prices[idx]+fn(idx+1,0,fee,prices);
            ll skip = fn(idx+1,1,fee,prices);
            return dp[idx][can_buy] = max(buy,skip);
        }else{
            ll sell = -fee+prices[idx]+fn(idx+1,1,fee,prices);
            ll skip = fn(idx+1,0,fee,prices);
            return dp[idx][can_buy] = max(sell,skip);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return fn(0,1,fee,prices);
    }
};