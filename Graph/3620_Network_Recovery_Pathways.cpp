#include <iostream>
#include<bits/stdc++.h>
using namespace std;


// using ll = long long;
// class Solution {
// public:
//     void dfs(ll node,ll curr_min,ll path_cost,ll & ans,ll k,ll
//     n,unordered_map<ll,vector<pair<ll,ll>>>& adj,vector<bool>& online){
//         if(path_cost>k) return;
//         if(node == n-1){
//             if(path_cost<=k){
//                 ans = max(ans,curr_min);
//             }
//             return;
//         }

//         for(auto it : adj[node]){
//             ll neigh = it.first;
//             ll wt = it.second;
//             if(!online[neigh]) continue;
//             ll new_curr_min = min(curr_min,wt);
//             dfs(neigh,new_curr_min,path_cost+wt,ans,k,n,adj,online);
//         }
//     }

//     int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
//     long long k) {
//        unordered_map<ll,vector<pair<ll,ll>>> adj;
//        ll n = (ll)online.size();
//        for(auto it : edges){
//         ll u = it[0];
//         ll v = it[1];
//         ll wt = it[2];
//         adj[u].push_back({v,wt});
//        }
//        ll ans = LONG_MIN;
//        dfs(0,LONG_MAX,0,ans,k,n,adj,online);
//        ll result = (ans == LONG_MIN)?-1:ans;
//        return result;
//     }
// };

using ll = long long;
class Solution {
public:
    // this dfs will return the min path cost from nodeto source
    ll dfs(ll node, ll min_wt_allowed, ll n,
           unordered_map<ll, vector<pair<ll, ll>>>& adj, vector<bool>& online,
           vector<ll>& dp) {
        if (node == n - 1) {
            return 0; // Base reached no more path to add cost so return 0
        }

        if (dp[node] != -1)
            return dp[node];
        ll min_cost = LONG_MAX;

        for (auto it : adj[node]) {
            ll neigh = it.first;
            ll wt = it.second;
            if (!online[neigh])
                continue;
            if (wt < min_wt_allowed)
                continue;

            ll sub_cost = dfs(neigh, min_wt_allowed, n, adj, online, dp);
            if (sub_cost == LONG_MAX)
                continue;
            min_cost = min(min_cost, wt + sub_cost);
        }

        return dp[node] = min_cost;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        unordered_map<ll, vector<pair<ll, ll>>> adj;
        ll n = (ll)online.size();
        for (auto it : edges) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            adj[u].push_back({v, wt});
        }

        ll ans = -1;
        ll l = 0;
        ll r = 1e9;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            vector<ll> dp(n, -1);
            ll min_path_cost_with_mid_wt = dfs(0, mid, n, adj, online, dp);
            if (min_path_cost_with_mid_wt <= k) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};