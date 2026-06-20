#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int dp[50005];
    int upper_bound(int val,vector<int>& endTime){
        int l = 0;
        int r = endTime.size()-1;
        int ans = r+1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(endTime[mid]>=val){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int fn(int idx, int n , vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        if(idx == n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int left = INT_MIN;
        int right = INT_MIN;
        left = profit[idx] + fn(upper_bound(endTime[idx],startTime),n,startTime,endTime,profit);
        right = fn(idx+1,n,startTime,endTime,profit);
        return dp[idx]=max(right,left);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        int n = startTime.size();
        multiset<pair<int,int>> ms;
        for(int i = 0 ; i<n ; i++){
            ms.insert({startTime[i],i});
        }
        vector<int> n_start;
        vector<int> n_end;
        vector<int> n_profit;

        for(auto it : ms){
            int idx = it.second;
            n_start.push_back(startTime[idx]);
            n_end.push_back(endTime[idx]);
            n_profit.push_back(profit[idx]);
        }

        // for(int x : n_start){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(int x : n_end){
        //     cout << x << " ";
        // }
        // cout << endl;
        // for(int x : n_profit){
        //     cout << x << " ";
        // }
        // cout << endl;
        return fn(0,n,n_start,n_end,n_profit);
    }
};