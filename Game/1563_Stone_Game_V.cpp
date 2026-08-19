#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int fn(int l,int r,vector<int>& stoneValue){
        if(r-l+1 == 1) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int idx = -1;
        int diff = INT_MAX;
        int n = stoneValue.size();
        // for(int i = l ; i<=r ; i++){
        //     cout << stoneValue[i] << " ";
        // }
        // cout << endl;
        int ans;
        for(int i = l; i < r ; i++){
            int val_left = stoneValue[i] - ((l-1>=0)?stoneValue[l-1]:0);
            int val_right = stoneValue[r] - stoneValue[i];

            if(val_right==val_left){
                ans = max(val_right+fn(l,i,stoneValue) , val_right+fn(i+1,r,stoneValue));
            }else{
                if(val_right>val_left){
                    ans = max(ans,val_left + fn(l,i,stoneValue));
                }else{
                    ans = max(ans,val_right + fn(i+1,r,stoneValue));
                }
            }
        }
        
        
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 1; i<n ; i++){
            stoneValue[i] += stoneValue[i-1];
        }
        return fn(0,n-1,stoneValue);
    }
};