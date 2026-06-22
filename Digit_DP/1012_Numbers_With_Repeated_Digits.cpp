#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[11][2][2][2][1<<10];
    int solve(int idx,bool tight,bool isLeadingZero,bool is_repeated,int mask,string & s){
        if(idx == s.size()){
            return is_repeated;
        }
        if(dp[idx][tight][isLeadingZero][is_repeated][mask]!=-1) return dp[idx][tight][isLeadingZero][is_repeated][mask];

        int limit = (tight)?s[idx]-'0':9;
        int ans = 0;
        for(int i = 0; i<= limit ; i++){
            bool newIsLeadingZero = isLeadingZero && (i==0);
            bool new_is_repeated = (newIsLeadingZero==1) ?is_repeated : is_repeated | (mask & (1<<i));
            int new_mask = (newIsLeadingZero==1) ? mask : mask | (1<<i);
            ans += solve(idx+1,tight&&(i==s[idx]-'0'),newIsLeadingZero,new_is_repeated,new_mask,s);
        }
        return dp[idx][tight][isLeadingZero][is_repeated][mask] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        int mask = 0;
        return solve(0,1,1,0,mask,s);

    }
};