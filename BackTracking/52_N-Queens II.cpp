#include <iostream>
#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    map<pair<int,int>,int> mp;
    void mark_visited(int p, int q, int n){
        // Upper diagonal
        int r = p, c = q;
        while(r>=0&&c<n){
            r--;
            c++;
            mp[{r,c}]+=1;
        }

        // Horizontal
        r = p, c = q;
        while(c<n){
            c++;
            mp[{r,c}]+=1;
        }

        // Lower diagonal
        r = p, c = q;
        while(c<n&&r<n){
            r++;
            c++;
            mp[{r,c}]+=1;
        }
    }

    void mark_unvisited(int p, int q, int n){
        // Upper diagonal
        int r = p, c = q;
        while(r>=0&&c<n){
            r--;
            c++;
            mp[{r,c}]-=1;
            if(mp[{r,c}]==0) mp.erase({r,c});
        }

        // Horizontal
        r = p, c = q;
        while(c<n){
            c++;
            mp[{r,c}]-=1;
            if(mp[{r,c}]==0) mp.erase({r,c});
        }

        // Lower diagonal
        r = p, c = q;
        while(c<n&&r<n){
            r++;
            c++;
            mp[{r,c}]-=1;
            if(mp[{r,c}]==0) mp.erase({r,c});
        }
    }

    void helper(int col,int n,vector<vector<int>> & grid,vector<vector<string>>& ans){
        if(col == n){
            vector<string> ds;
            for(int i = 0 ; i<n ; i++){
                string s = "";
                for(int j = 0 ; j<n ; j++){
                    if(grid[i][j]==0) s+='.';
                    else s+='Q';
                }
                ds.push_back(s);
            }
            ans.push_back(ds);
            return;
        }

        for(int i = 0 ; i<n ; i++){
            if(mp[{i,col}]) continue;
            grid[i][col]=1;
            mark_visited(i,col,n);
            helper(col+1,n,grid,ans);
            mark_unvisited(i,col,n);
            grid[i][col]=0;
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<vector<string>> ans;
        helper(0,n,grid,ans);
        return (int)ans.size();
    }
};
