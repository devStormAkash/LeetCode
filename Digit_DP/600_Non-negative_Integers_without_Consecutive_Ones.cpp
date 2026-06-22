#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[32][2][2];
    int solve(int idx, bool prev ,bool tight, int n, string & s){ // prev stores that if previous bit is 1 or not
        if(idx == n){
            return 1;
        }
        if(dp[idx][prev][tight]!=-1) return dp[idx][prev][tight];
        int limit = (tight == 1) ? s[idx]-'0':1;
        int ans = 0;
        for(int i = 0 ; i<=limit ; i++){
            if(i == 1 && prev) break;
            ans += solve(idx+1,(i==1),(tight && (i == s[idx]-'0')),n,s);
        }
        return dp[idx][prev][tight] = ans;
    }

    int findIntegers(int n) {
        memset(dp,-1,sizeof(dp));
        string s = bitset<32>(n).to_string();
        s.erase(0,s.find_first_not_of('0'));
        return solve(0,0,1,s.size(),s);
    }
};