#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[100001];
    bool fn(int n,vector<int> & square){ // turn 1 for alice and 0 for bob
        if(n==0) return false;

        if(dp[n]!=-1) return dp[n];

        int sz = square.size();
        int i = 0;
        while(i<sz&&square[i]<=n){
            if(!fn(n-square[i],square)) return dp[n] = true;
            i++;
        }
    
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int> square;
        for(int i = 1; i*i<=n ; i++){
            square.push_back(i*i);
        }

        bool ans = fn(n,square);
        return ans;
    }
};