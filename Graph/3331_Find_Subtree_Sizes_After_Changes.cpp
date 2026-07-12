#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    void dfs1(ll node,ll par,string &s,unordered_map<ll,vector<ll>>& mp,vector<vector<ll>> & track,vector<int>& parent){
        ll track_idx = s[node]-'a';
        if(!track[track_idx].empty()){
            parent[node] = track[track_idx].back();
        }

        track[track_idx].push_back(node);

        for(auto child : mp[node]){
            if(child==par) continue;
            dfs1(child,node,s,mp,track,parent);
        }

        track[track_idx].pop_back();
    }

    ll dfs2(ll node, ll par, unordered_map<ll,vector<ll>>& mp,vector<int>& ans){
        ll sum = 0;
        for(auto child : mp[node]){
            if(child == par) continue;
            sum+=dfs2(child,node,mp,ans);
        }
        ans[node] = sum+1;
        return ans[node];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        ll n = parent.size();
        unordered_map<ll,vector<ll>> mp;
        for(ll i = 1; i<n ; i++){
            ll u = i;
            ll v = parent[u];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<vector<ll>> track(26);
        // this dfs is for rearranging the tree structure
        dfs1(0,-1,s,mp,track,parent);
        // for(ll i = 0; i<n ; i++){
        //     cout << parent[i] << "-->" << i << endl;
        // }

        // this dfs is for calculating subtree sizes
        // now create new adjacency list according to new parent
        unordered_map<ll,vector<ll>> adj;
        for(ll i = 1; i<n ; i++){
            ll u = i;
            ll v = parent[u];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n);
        dfs2(0,-1,adj,ans);

        return ans;

    }
};