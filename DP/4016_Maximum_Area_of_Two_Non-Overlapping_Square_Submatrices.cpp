#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i = 0; i<m ; i++){
            for(int j = 0; j<n ; j++){
                if(mat[i][j] == 1){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    }
                }
            }
        }

        int l = 1;
        int r = min(m,n);
        int ans = 0;

        while(l<=r){
            int mid = l+(r-l)/2;
            int min_r = 1e9,max_r = -1e9;
            int min_c = 1e9 , max_c = -1e9;

            for(int i = 0; i<m ; i++){
                for(int j = 0; j<n ; j++){
                    if(dp[i][j]>=mid){
                        min_r = min(min_r,i);
                        max_r = max(max_r,i);
                        min_c = min(min_c,j);
                        max_c = max(max_c,j);
                    }
                }
            }

            if(max_r - min_r >= mid || max_c-min_c>=mid){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans*ans;
    }
};