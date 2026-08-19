#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    void height(ll node,ll par,ll d,ll & ht,unordered_map<ll,vector<ll>> & adj){
        ht = max(ht,d);
        for(auto neigh:adj[node]){
            if(neigh == par) continue;
            height(neigh,node,d+1,ht,adj);
        }
    }

    ll dfs(ll node,ll par,ll d,ll ht,vector<int>& nums,unordered_map<ll,vector<ll>> & adj){
        ll val = nums[node]*(ht-d+1);
        ll sum = 0;
        for(ll neigh : adj[node]){
            if(neigh == par) continue;
            sum += dfs(neigh,node,d+1,ht,nums,adj);
        }

        return val+sum;
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        unordered_map<ll,vector<ll>> adj;
        ll n = parent.size();
        for(ll i = 1; i<n ; i++){
            ll u = i;
            ll v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ht = LONG_MIN;
        height(0,-1,1,ht,adj);
        ll ans = dfs(0,-1,1,ht,nums,adj);
        return ans;
    }
};