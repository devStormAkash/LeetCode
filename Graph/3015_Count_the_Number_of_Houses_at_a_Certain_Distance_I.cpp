#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        vector<vector<int>> grid(n,vector<int>(n,1e9));
        for(int i = 0; i<n ; i++) grid[i][i] = 0;
        grid[x-1][y-1]=1;
        grid[y-1][x-1]=1;
        for(int i = 1; i<n ; i++){
            grid[i-1][i]=1;
            grid[i][i-1]=1;
        }

        for(int k = 0; k<n ; k++){
            for(int i = 0; i<n ; i++){
                for(int j = 0; j<n ; j++){
                    if(grid[i][k]!=1e9 && grid[k][j]!=1e9){
                        grid[i][j] = min(grid[i][j],grid[i][k]+grid[k][j]);
                    }
                }
            }
        }

        // for(auto v : grid){
        //     for(auto x : v){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j]>0 && grid[i][j]!=1e9 && i!=j) ans[grid[i][j]-1]+=1;
            }
        }
        return ans;
    }
};