#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int solve(int idx, bool tight,bool isLeadingZero, set<int>& vis, string& s){
//         if(idx == s.size()) return 1;
//         int limit = (tight == 1)? s[idx]-'0':9;
//         int ans = 0;
//         for(int i = 0; i<= limit ; i++){
//             if(!vis.count(i) || isLeadingZero){
//                 bool newIsLeadingZero = isLeadingZero && (i==0);
//                 if(!newIsLeadingZero) vis.insert(i);
//                 ans += solve(idx+1,tight&&s[idx]-'0'==i,newIsLeadingZero,vis,s);
//                 if(!newIsLeadingZero) vis.erase(i);
//             }
//         }
//         return ans;

//     }
//     int countSpecialNumbers(int n) {
//         string s = to_string(n);
//         set<int> vis;
//         return solve(0,1,1,vis,s)-1;
//     }
// };

// To avoid TLE error we will use bitmask in place of the set
class Solution {
public:
    int dp[11][2][2][1024];
    int solve(int idx, bool tight,bool isLeadingZero, int mask, string& s){
        if(idx == s.size()) return 1;
        if(dp[idx][tight][isLeadingZero][mask] != -1) return dp[idx][tight][isLeadingZero][mask];
        int limit = (tight == 1)? s[idx]-'0':9;
        int ans = 0;
        for(int i = 0; i<= limit ; i++){
            // (mask & (1<<i)) == 0 that means i is not previously used
            if( (mask & (1<<i)) == 0 || isLeadingZero){
                bool newIsLeadingZero = isLeadingZero && (i==0);
                int new_mask = (newIsLeadingZero == 1)? mask : mask|(1<<i);
                ans += solve(idx+1,tight&&s[idx]-'0'==i,newIsLeadingZero,new_mask,s);
            }
        }
        return dp[idx][tight][isLeadingZero][mask] = ans;

    }
    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        int mask = 0;
        return solve(0,1,1,mask,s)-1;
    }
};