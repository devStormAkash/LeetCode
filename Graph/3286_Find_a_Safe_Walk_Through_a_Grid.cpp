#include <iostream>
#include<bits/stdc++.h>
using namespace std;


using ll = long long;
using tlll = tuple<ll,ll,ll>;
// using pll = pair<ll,ll>
class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        ll m = grid.size();
        ll n = grid[0].size();
        deque<tlll> dq;

        vector<vector<ll>> mat(m,vector<ll>(n,LONG_MAX));
        ll cost = (grid[0][0]==0)?0:1;
        dq.push_front({cost,0,0});
        mat[0][0] = cost;
        
        while(!dq.empty()){
            auto [cost,row,col] = dq.front();
            if(row == m-1 && col == n-1 && cost<health) return true;
            dq.pop_front();

            for(ll k = 0; k<4; k++){
                ll nr = row+dr[k];
                ll nc = col+dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    ll new_cost = cost+grid[nr][nc];
                    if (new_cost >= health) continue;
                    if(new_cost<mat[nr][nc]){
                        mat[nr][nc] = new_cost;
                        if(grid[nr][nc]==0){
                            dq.push_front({new_cost,nr,nc});
                        }else{
                            dq.push_back({new_cost,nr,nc});
                        }
                    }
                }
            }
        }

        return false;
    }
};