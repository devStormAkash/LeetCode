#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][201];
    int fn(int idx,int m,int n,vector<int>& arr){
        if(idx>=n) return 0;
        if(dp[idx][m]!=-1) return dp[idx][m];

        int ans = INT_MIN;
        for(int i = idx; i<idx+2*m && i<n; i++){
            int val = arr[i] - ((idx-1>=0)?arr[idx-1]:0);
            ans = max(ans,val-fn(i+1,max(m,i-idx+1),n,arr));
        }
        return dp[idx][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        vector<int> arr(n);
        arr[0] = piles[0];
        for(int i = 1; i<n ; i++){
            arr[i] = arr[i-1] + piles[i];
        }

        int diff = fn(0,1,n,arr);
        int total = accumulate(begin(piles),end(piles),0);
        return (total+diff)/2;
    }
};