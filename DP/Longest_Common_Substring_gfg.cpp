#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int ans = 0;
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> grid(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<=n ; j++){
                if(s1[i-1]==s2[j-1]){
                    grid[i][j] = grid[i-1][j-1]+1;
                }
            }
        }
        
        for(int i = 1; i<=m ; i++){
            for(int j = 1; j<=n ; j++){
                ans = max(ans,grid[i][j]);
            }
        }
        
        return ans;
        
    }
};