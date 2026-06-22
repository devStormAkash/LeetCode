#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int mod = 1e9+7;
    ll dp[25][2][210]; // idx , tight , sum
    ll solve(int idx , bool tight , ll sum ,string & s , int min_sum, int max_sum){
        if(idx == s.size()) return (sum>=min_sum) && (sum<=max_sum); // if it is true return 1 else return 0
        if(dp[idx][tight][sum]!=-1) return dp[idx][tight][sum];
        
        ll ans = 0;
        int limit = tight == 1 ? s[idx]-'0':9;
        for(int i=0; i<=limit ; i++){
            ll updsum = sum+i;
            ans = (ans + (solve(idx+1,tight && i == s[idx]-'0',updsum,s,min_sum,max_sum))%mod)%mod;
        }

        return dp[idx][tight][sum] = ans;
    }

    string subtract_one(string  s){
        int i = s.size()-1;
        while(i>=0 && s[i]=='0'){
            s[i]='9';
            i--;
        }
        if(i>=0){
            int x = s[i]-'0';
            x--;
            s[i]=x+'0';
        }

        i = 0;
        while(i<s.size() && s[i] == '0'){
            i++;
        }
        return s.substr(i);
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1,sizeof(dp));
        string num1_minus_1 = subtract_one(num1);
        ll left = (solve(0,1,0,num1_minus_1,min_sum,max_sum)%mod);
        memset(dp,-1,sizeof(dp));
        ll right = (solve(0,1,0,num2,min_sum,max_sum)%mod);
        // standard competitive programming trick
        // (a - b + mod) % mod to safely calculate (a - b) % mod
        return (int)(right - left+mod)%mod;
    }
};