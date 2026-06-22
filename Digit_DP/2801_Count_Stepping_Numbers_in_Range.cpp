#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int mod = 1e9+7;
    string subtract_one(string s){
        int i = s.size()-1;
        while(i>=0 && s[i]=='0'){
            s[i]='9';
            i--;
        }
        if(i>=0){
            int x = s[i]-'0';
            x--;
            s[i] = x+'0';
        }
        s.erase(0,s.find_first_not_of('0'));
        // cout << s;
        if(s.empty()) return "0";
        return s;
    }
    ll dp[102][2][2][12];
    ll solve(int idx, bool tight,bool isLeadingZero, int prev , string & s){
        if(idx == s.size()) return 1;

        // Map prev from [-1, 9] to [0, 10] to avoid negative array index
        int p_ind = prev+1;
        if(dp[idx][tight][isLeadingZero][p_ind] != -1) return dp[idx][tight][isLeadingZero][p_ind];

        int limit = (tight == 1)? s[idx]-'0':9;
        ll ans = 0;
        for(int i = 0 ; i <= limit ; i++){
            if(prev == -1 || abs(i-prev) == 1 || isLeadingZero){
                bool newIsLeadingZero = isLeadingZero && i == 0;
                int newPrev = newIsLeadingZero == 1? -1 : i;
                ans = (ans + solve(idx+1,tight && (i == s[idx]-'0'),newIsLeadingZero,newPrev,s))%mod;
            }
        }
        
        return dp[idx][tight][isLeadingZero][p_ind] = ans;
    }

    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        string low_minus_one = subtract_one(low);
        int left = solve(0,1,1,-1,low_minus_one);
        memset(dp,-1,sizeof(dp));
        int right = solve(0,1,1,-1,high);
        return (right-left+mod)%mod;
    }
};