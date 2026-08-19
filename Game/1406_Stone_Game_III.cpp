#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int dp[50009];
//     int fn(int idx,int n,vector<int>& arr){
//         if(idx>=arr.size()) return 0;
//         if(dp[idx]!=INT_MIN) return dp[idx];

//         int take_1 = INT_MIN;
//         int take_2 = INT_MIN;
//         int take_3 = INT_MIN;

//         take_1 = arr[idx] - fn(idx+1,n,arr);
//         if(idx+1<n)
//             take_2 = arr[idx]+arr[idx+1] - fn(idx+2,n,arr);
//         if(idx+2<n)
//             take_3 = arr[idx]+arr[idx+1]+arr[idx+2] - fn(idx+3,n,arr);

//         return dp[idx] = max({take_1,take_2,take_3});
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();
//         fill(dp,dp+n+1,INT_MIN);

//         int diff = fn(0,n,stoneValue);

//         if(diff>0){
//             return "Alice";
//         }else if(diff<0){
//             return "Bob";
//         }else{
//             return "Tie";
//         }
//     }
// };

class Solution {
public:
    int dp[50009];

    int fn(int idx, int n, vector<int>& arr) {
        if (idx >= n) return 0;
        if (dp[idx] != INT_MIN) return dp[idx];

        int take = 0;
        int best = INT_MIN;

        for (int k = 0; k < 3 && idx + k < n; ++k) {
            take += arr[idx + k];
            best = max(best, take - fn(idx + k + 1, n, arr));
        }

        return dp[idx] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // Only reset the memory needed for this specific test case
        fill(dp, dp + n + 1, INT_MIN);

        int diff = fn(0, n, stoneValue);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};