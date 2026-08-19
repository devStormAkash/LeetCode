#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll dp[500][500];
    // Calculate only the score of ALICE
    ll fn(ll i, ll j, vector<int>& piles){
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        ll take_i = piles[i] + min(fn(i+1,j-1,piles),fn(i+2,j,piles));
        ll take_j = piles[j] + min(fn(i+1,j-1,piles),fn(i,j-2,piles));
        return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        ll total_score = accumulate(begin(piles),end(piles),0);
        ll alice_score = fn(0,piles.size()-1,piles);
        ll bob_score = total_score - alice_score;
        if(alice_score>bob_score) return 1;
        return 0;
    }
};