#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[20][20];
    
    int fn(int l, int r, vector<int>& piles) {
        // Base case: no more piles left
        if (l > r) return 0;

        // Return memoized result
        if (dp[l][r] != -1) return dp[l][r];

        // Current player takes left pile, minus opponent's best future score
        int pickLeft = piles[l] - fn(l + 1, r, piles);
        
        // Current player takes right pile, minus opponent's best future score
        int pickRight = piles[r] - fn(l, r - 1, piles);
        
        // Current player wants to maximize their net difference
        return dp[l][r] = max(pickLeft, pickRight);
    }
    
    bool predictTheWinner(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        // If the max score difference for the first player (Alice) is > 0, she wins.
        int n = piles.size();
        if(n==1) return 1;
        return fn(0, piles.size() - 1, piles) >= 0;
    }
};