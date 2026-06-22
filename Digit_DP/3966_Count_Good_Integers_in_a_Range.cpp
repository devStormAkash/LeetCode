#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    ll dp[17][2][2][11];
    ll solve(int idx, bool tight,bool isLeadingZero, int prev , string & s, int k){
        if(idx == s.size()) return 1;

        // prev range (-1,9) map into (0,10)
        int p_ind = prev+1;
        if(dp[idx][tight][isLeadingZero][p_ind]!=-1) return dp[idx][tight][isLeadingZero][p_ind];

        int limit = (tight)? s[idx]-'0':9;
        ll ans = 0;
        for(int i = 0 ; i<= limit ; i++){
            bool newIsLeadingZero = isLeadingZero && (i==0);
            int newPrev = (newIsLeadingZero)? -1 : i;
            if(prev == -1 || abs(i-prev)<=k){
                ans += solve(idx+1,tight&&(i == s[idx]-'0'),newIsLeadingZero,newPrev,s,k);
            }
        }
        return dp[idx][tight][isLeadingZero][p_ind] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        memset(dp,-1,sizeof(dp));
        string low = to_string(l-1);
        string high = to_string(r);
        ll lw = solve(0,1,1,-1,low,k);
        memset(dp,-1,sizeof(dp));
        ll hg = solve(0,1,1,-1,high,k);
        return hg-lw;
    }
};