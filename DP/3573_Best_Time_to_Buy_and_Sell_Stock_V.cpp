#include <iostream>
#include<bits/stdc++.h>
using namespace std;


using ll = long long;
class Solution {
public:
    ll dp[1001][3][2][505];
    ll fn(ll idx,ll type , bool is_running , ll k ,int n , vector<int>& prices){
        if(k==0) return 0;
        if(idx>=n){
            // FIX: If we are not mid-transaction, it is perfectly valid to end with k > 0.
            if(!is_running) return 0;
            else return -1e18;// We are in the mid of a transaction and it is not a valid possibility
        }
        
        if(dp[idx][type][is_running][k]!=-1) return dp[idx][type][is_running][k];

        if(!is_running){// transaction not started yet
            ll buy     = -prices[idx] + fn(idx+1,0,1,k,n,prices);
            ll sell    = prices[idx]  + fn(idx+1,1,1,k,n,prices);
            ll skip    = 0            + fn(idx+1,2,0,k,n,prices);
            return dp[idx][type][is_running][k]=max({buy,sell,skip});
        }else{
            ll ans = -1e18;
            if(type == 0){
                ll sell     = prices[idx] + fn(idx+1,2,0,k-1,n,prices);
                ll not_sell = 0           + fn(idx+1,0,1,k,n,prices);
                ans = max({ans,sell,not_sell});
            }else if(type == 1){
                ll buy      = -prices[idx] + fn(idx+1,2,0,k-1,n,prices);
                ll not_buy  = 0            + fn(idx+1,1,1,k,n,prices);
                ans = max({ans,buy,not_buy});
            }
            return dp[idx][type][is_running][k]=ans;
        }
    }

    long long maximumProfit(vector<int>& prices, int k) {
        ll n = prices.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,2,0,k,n,prices);
    }
};