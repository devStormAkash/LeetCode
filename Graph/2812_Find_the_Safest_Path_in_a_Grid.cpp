#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
using ti = tuple<int,int>;
class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};

    // check if it is possible to get the path with min target distance
    bool bfs(int i, int j, int target ,int m , int n, vector<vector<int>> & dist){
        queue<ti> q;
        q.push({i,j});
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[0][0]=1;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(r==m-1&&c==n-1) return true;
            for(int k = 0; k<4 ; k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && dist[nr][nc]>=target){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }

        // Apply multi source bfs to get the distance
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i<4 ; i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && dist[nr][nc]==INT_MAX){
                        dist[nr][nc] = dist[r][c]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        // for(auto v : dist){
        //     for(auto x : v){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        // apply binary search 
        int ans = 0;
        int l = 0;
        int r = min(dist[0][0], dist[m-1][n-1]);
        while(l<=r){
            int mid = l+(r-l)/2;
            if(bfs(0,0,mid,m,n,dist)){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;

    }
};