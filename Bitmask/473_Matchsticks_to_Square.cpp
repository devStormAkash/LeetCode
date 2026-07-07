#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool makesquare(vector<int>& matchsticks) {
//         int s = accumulate(begin(matchsticks),end(matchsticks),0);
//         if(s%4) return false;
//         int sum = s/4;
//         int n = matchsticks.size();
//         vector<int> dp(1<<n,-1); // dp[mask] will store (sum of elements in mask) % target
//         dp[0] = 0; // because when there is no element sum is 0

//         for(int mask = 0; mask<(1<<n) ; mask++){
//             if(dp[mask]==-1) continue; // that means that sum is unreachable with the selected elements
//             for(int i = 0; i<n ; i++){
//                 if(mask&(1<<i)) continue;
//                 if(dp[mask]+matchsticks[i]>sum) continue;
//                 int new_mask = mask|(1<<i);
//                 dp[new_mask] = (dp[mask]+matchsticks[i])%sum;
//             }
//         }

//         return dp[(1<<n)-1]==0;
//     }
// };



class Solution {
public:
    int n;
    int sum;
    int dp[1<<15];

    bool dfs(int mask,int currSum,vector<int>& matchsticks){
        if(mask == (1<<n)-1) return currSum == 0;

        if(dp[mask]!=-1) return dp[mask];

        for(int i = 0; i<n ; i++){
            if(mask&(1<<i)) continue;
            if(currSum+matchsticks[i]>sum) continue;
            int new_mask = mask|(1<<i);
            int new_currSum = (currSum+matchsticks[i])%sum;
            if(dfs(new_mask,new_currSum,matchsticks)) return dp[mask] = true;
        }

        return dp[mask] = false;
    }
    bool makesquare(vector<int>& matchsticks) {
        n = matchsticks.size();
        int s = accumulate(begin(matchsticks),end(matchsticks),0);
        if(s%4) return false;
        sum = s/4;
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,matchsticks);
    }
};