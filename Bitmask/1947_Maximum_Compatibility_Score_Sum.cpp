#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int n;
    int dp[1<<8];
    int dfs(int mask,vector<vector<int>>& students,vector<vector<int>>& mentors){
        if(mask == (1<<n)-1) return 0;

        if(dp[mask]!=-1) return dp[mask];

        int ans = INT_MIN;
        int st = __builtin_popcount(mask);
        for(int i = 0; i<n ; i++){
            if(mask&(1<<i)) continue;
            int temp = 0;
            for(int j=0;j<students[0].size();j++){
                if(mentors[i][j]==students[st][j]) temp++;
            }
            ans = max(ans,temp+dfs(mask|(1<<i),students,mentors));
        }
        return dp[mask]=ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        memset(dp,-1,sizeof(dp));
        n = students.size();
        return dfs(0,students,mentors);
    }
};