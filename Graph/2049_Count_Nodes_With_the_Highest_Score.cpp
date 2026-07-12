#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll dfs(ll node , ll parent ,ll &n, unordered_map<ll,vector<ll>> & mp,unordered_map<ll,ll>& score){
        ll total_size = 0;
        ll mul_of_size = 1;
        for(auto child : mp[node]){
            if(child == parent) continue;
            ll x = dfs(child,node,n,mp,score);
            total_size+=x;
            mul_of_size*=x;
        }
        ll size_of_upper_nodes = n-total_size-1;
        if(size_of_upper_nodes>0){
            mul_of_size*=size_of_upper_nodes;
        }
        score[mul_of_size]+=1;
        return total_size+1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        unordered_map<ll,vector<ll>> mp;
        unordered_map<ll,ll> score;
        for(ll i = 1; i < parents.size() ; i++){
            ll u = i;
            ll v = parents[u];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        ll n = parents.size();
        dfs(0,-1,n,mp,score);
        ll ans;
        ll maxi = LONG_MIN;
        for(auto it : score){
            if(it.first>maxi){
                maxi = it.first;
                ans = score[maxi];
            }
        }
        return ans;
    }
};