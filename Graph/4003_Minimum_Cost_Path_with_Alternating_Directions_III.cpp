#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using tl = tuple<ll,ll,ll,ll>;
class Solution{
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<tl,vector<tl>,greater<tl>> pq;
        pq.push({1,1,0,0});// {cost,parity,row,col}
        vector<vector<vector<ll>>> min_cost(m, vector<vector<ll>>(n, vector<ll>(2, 1e18)));
        min_cost[0][0][1] = 1;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[0][0] = 1;
        while(!pq.empty()){
            auto [cost,parity,r,c] = pq.top();
            pq.pop();
            if(cost>min_cost[r][c][parity]) continue;
            if(parity==1){
                // right
                if(c+1<n && cost+(c+1+1)*(r+1)<min_cost[r][c+1][!parity]){
                    min_cost[r][c+1][!parity] = cost+(c+1+1)*(r+1);
                    pq.push({min_cost[r][c+1][!parity],0,r,c+1});
                }
                // down
                if(r+1<m && cost+(r+1+1)*(c+1)<min_cost[r+1][c][!parity]){
                    min_cost[r+1][c][!parity] = cost+(r+1+1)*(c+1);
                    pq.push({min_cost[r+1][c][!parity],0,r+1,c});
                }
                // up
                if(r-1>=0 && cost+(r)*(c+1)+penalty[r][c]<min_cost[r-1][c][!parity]){
                    min_cost[r-1][c][!parity] = cost+(c+1)*r+penalty[r][c];
                    pq.push({min_cost[r-1][c][!parity],0,r-1,c});
                }
                // left
                if(c-1>=0 && cost+(r+1)*(c)+penalty[r][c]<min_cost[r][c-1][!parity]){
                    min_cost[r][c-1][!parity] = cost+(c)*(r+1)+penalty[r][c];
                    pq.push({min_cost[r][c-1][!parity],0,r,c-1});
                }
            }
            if(parity==0){
                // right
                if(c+1<n && cost+(c+1+1)*(r+1)+penalty[r][c]<min_cost[r][c+1][!parity]){
                    min_cost[r][c+1][!parity] = cost+(c+1+1)*(r+1)+penalty[r][c];
                    pq.push({min_cost[r][c+1][!parity],1,r,c+1});
                }
                // down
                if(r+1<m && cost+(r+1+1)*(c+1)+penalty[r][c]<min_cost[r+1][c][!parity]){
                    min_cost[r+1][c][!parity] = cost+(r+1+1)*(c+1)+penalty[r][c];
                    pq.push({min_cost[r+1][c][!parity],1,r+1,c});
                }
                // up
                if(r-1>=0 && cost+(r)*(c+1)<min_cost[r-1][c][!parity]){
                    min_cost[r-1][c][!parity] = cost+(c+1)*r;
                    pq.push({min_cost[r-1][c][!parity],1,r-1,c});
                }
                // left
                if(c-1>=0 && cost+(r+1)*(c)<min_cost[r][c-1][!parity]){
                    min_cost[r][c-1][!parity] = cost+(c)*(r+1);
                    pq.push({min_cost[r][c-1][!parity],1,r,c-1});
                }
            }

            // waiting
            ll nc = cost + penalty[r][c];

            if(nc < min_cost[r][c][!parity]){
                min_cost[r][c][!parity] = nc;
                pq.push({nc,!parity,r,c});
            }
            
        }
        return min(min_cost[m-1][n-1][0],min_cost[m-1][n-1][1]);
    }
};




