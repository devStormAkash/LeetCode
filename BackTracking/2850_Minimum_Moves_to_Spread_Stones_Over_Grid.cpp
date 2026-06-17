#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    
    // int dfs(int sr,int sc,int er,int ec,vector<vector<int>>& grid,vector<vector<bool>>& vis){
    //     if(sr == er && sc == ec){
    //         return 0;
    //     }
        
    //     int steps = INT_MAX;
    //     vis[sr][sc]=1;
    //     for(int i = 0 ; i<4 ; i++){
    //         int nr = sr+dr[i];
    //         int nc = sc+dc[i];
    //         if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && !vis[nr][nc]){
    //             int sub_ans = dfs(nr,nc,er,ec,grid,vis);
    //             if(sub_ans!=INT_MAX){
    //                 steps = min(steps,sub_ans+1);
    //             }
    //         }
    //     }
    //     vis[sr][sc]=0;
    //     return steps;

    // }

    int manhattan_distance(int sr,int sc,int er,int ec){
        return abs(sr-er)+abs(sc-ec);
    }

    int minimumMoves(vector<vector<int>>& grid) {
        // memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> empty;
        vector<pair<int,int>> extra;
        for(int i = 0 ; i<3 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(grid[i][j]==0) empty.push_back({i,j});
                if(grid[i][j]>1){
                    while(grid[i][j]>1){
                        extra.push_back({i,j});
                        grid[i][j]--;
                    }
                }

            }
        }

        int n = empty.size();
        // for(int i = 0 ; i<n ; i++){
        //     cout<< empty[i].first << " " << empty[i].second << endl;
        // }
        // cout << "------------" << endl;
        // for(int i = 0 ; i<n ; i++){
        //     cout<< extra[i].first << " " << extra[i].second << endl;
        // }

        int total_steps = INT_MAX;
        sort(begin(extra),end(extra));

        do{ 
            int curr_steps = 0;
            for(int i = 0 ; i<n ; i++){
                curr_steps += manhattan_distance(empty[i].first,empty[i].second,extra[i].first,extra[i].second);
            }
            total_steps = min(total_steps,curr_steps);
        }while(next_permutation(begin(extra),end(extra)));

        return total_steps;

    }
};