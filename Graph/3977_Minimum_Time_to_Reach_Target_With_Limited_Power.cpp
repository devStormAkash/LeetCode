#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
typedef tuple<ll,ll,ll> tlll;
typedef pair<ll,ll> pll;
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        unordered_map<ll,vector<pll>> mp;
        for(auto it : edges){
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            mp[u].push_back({v,wt});
        }
        vector<vector<ll>> dist(n,vector<ll>(power+1,LONG_MAX));

        priority_queue<tlll,vector<tlll>,greater<tlll>> pq;
        pq.push({0,source,power});//{time,node,remaining_power_along_path}
        dist[source][power]=0;

        ll min_time = LONG_MAX;
        ll max_power = -1;

        while(!pq.empty()){
            auto [time,node,power] = pq.top();
            pq.pop();
            if(node == target){
                ll temp = time;
                min_time = min(min_time,time);
                if(temp == min_time){
                    max_power = max(max_power,power);
                }
            }

            if(time>dist[node][power]) continue;
            for(auto it : mp[node]){
                ll neigh = it.first;
                ll wt = it.second;
                ll new_power = power-cost[node];
                if(new_power<0) break;
                if(time+wt<dist[neigh][new_power]){
                    dist[neigh][new_power] = time+wt;
                    pq.push({dist[neigh][new_power],neigh,new_power});
                }
            }
        }

        if(min_time == LONG_MAX){
            return {-1,-1};
        }
        return {min_time,max_power};
    }
};