#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class DisjointSet{
    vector<ll> rank,parent;
    public:
        DisjointSet(ll n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(ll i = 0; i<=n ; i++){
                parent[i]=i;
            }
        }

        ll findUPar(ll u){
            if(parent[u]==u) return u;
            else return parent[u] = findUPar(parent[u]);
        }

        bool unionByRank(ll u, ll v){
            ll pu = findUPar(u);
            ll pv = findUPar(v);
            if(pu == pv) return false;
            if(rank[pu]<rank[pv]){
                parent[pu] = pv;
            }else if(rank[pu]>rank[pv]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
            return true;
        }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        ll m = queries.size();
        vector<bool> ans(m,false);
        DisjointSet ds(n);

        for(ll i = 0; i<n-1 ; i++){
            ll u = i;
            ll v = i+1;
            if(abs(nums[u] - nums[v]) <= maxDiff){
                ds.unionByRank(u,v);
            }
        }

        for(ll i = 0;i<m ; i++){
            ll u = queries[i][0];
            ll v = queries[i][1];
            ll pu = ds.findUPar(u);
            ll pv = ds.findUPar(v);
            if(pu == pv) ans[i]=true;
        }
        return ans;
    }
};