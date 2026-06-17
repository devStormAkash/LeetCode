#include <iostream>
#include<bits/stdc++.h>
using namespace std; 

// class Solution {
// public:
//     void helper(vector<vector<int>>& mat, vector<vector<string>>& ans,int n ,int row){
//         if(row == n){
//             vector<string> board;
//             for(int i = 0 ; i<n ; i++){
//                 string s="";
//                 for(int j = 0 ; j<n ;j++){
//                     if(mat[i][j]==1){
//                         s.push_back('.');
//                     }else{
//                         s.push_back('Q');
//                     }
//                 }
//                 board.push_back(s);
//             }
//             ans.push_back(board);

//             return;
//         }

// // Place the queen in every possible places so loop through it
//         for(int i = 0 ; i<n ; i++){
//             if(mat[row][i] == 1) continue;
//             else{
//                 mat[row][i] = 2;
//                 set<pair<int,int>> points;
//                 // Add horizontal coordinates
//                 for(int j = 0 ; j<n ; j++){
//                     if(j==i) continue;
//                     if(mat[row][j]==0){
//                         points.insert({row,j});
//                     }
//                 }
//                 // Add vertical coordinates
//                 for(int j = 0 ; j<n ; j++){
//                     if(j==row) continue;
//                     if(mat[j][i] == 0){
//                         points.insert({j,i});
//                     }

//                 }

//                 int p = row,q=i;
//                 p--,q++;

//                 // Add lower left diagonal coordinates
                
//                 while(p>=0&&q<n){
//                     if(mat[p][q]==0){
//                         points.insert({p,q});
//                     }
//                     p--,q++;
//                 }

//                 p = row,q=i;
//                 p++,q++;

//                 // Add lower right diagonal coordinates
                
//                 while(p<n&&q<n){
//                     if(mat[p][q]==0){
//                         points.insert({p,q});
//                     }
//                     p++,q++;
//                 }

//                 p = row,q=i;
//                 p++,q--;

//                 // Add upper right diagonal coordinates
                
//                 while(p<n&&q>=0){
//                     if(mat[p][q]==0){
//                         points.insert({p,q});
//                     }
//                     p++,q--;
//                 }

//                 p = row,q=i;
//                 p--,q--;

//                 // Add upper left diagonal coordinates

//                 while(p>=0&&q>=0){
//                     if(mat[p][q]==0){
//                         points.insert({p,q});
//                     }
//                     p--,q--;
//                 }

//                 // Make all these points 1
//                 for(auto &x : points){
//                     mat[x.first][x.second] = 1;
//                 }

//                 helper(mat,ans,n,row+1);
                
//                 // Make all these points 0 again backtrack
//                 for(auto &x : points){
//                     mat[x.first][x.second] = 0;
//                 }

//                 mat[row][i] = 0;
//             }
//         }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<int>> mat(n,vector<int>(n,0));
//         vector<vector<string>> ans;
//         helper(mat,ans,n,0);
//         return ans;
//     }
// };






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
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        vector<vector<string>> ans;
        helper(0,n,grid,ans);
        return ans;
    }
};