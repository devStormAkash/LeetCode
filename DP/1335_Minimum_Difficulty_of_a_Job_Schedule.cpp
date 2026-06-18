#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int findMax(vector<int>& arr,int i , int j){
        int maxi = INT_MIN;
        for(int x = i ; x <= j ; x++){
            maxi = max(maxi,arr[x]);
        }
        return maxi;
    }
    int dp[301][11];
    int fn(int idx,int d,vector<int>& arr){
        if(idx == arr.size()) return INT_MAX;
        if(d==1) return findMax(arr,idx,arr.size()-1);

        if(dp[idx][d] != -1) return dp[idx][d];
        int ans = INT_MAX;
        for(int i = idx; i<arr.size() ; i++){
            int sub_ans = fn(i+1,d-1,arr);
            if(sub_ans!=INT_MAX) ans = min(ans,findMax(arr,idx,i)+sub_ans);
        }
        return dp[idx][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
        int ans = fn(0,d,jobDifficulty);
        return ans == INT_MAX?-1:ans;
    }
};