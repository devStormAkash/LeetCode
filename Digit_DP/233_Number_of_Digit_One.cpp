#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int dp[10][2][11];
//     int solve(int idx,bool tight, int count, string & s){
//         if(idx == s.size()) return count;

//         if(dp[idx][tight][count]!=-1) return dp[idx][tight][count];

//         int limit = (tight == 1) ? s[idx]-'0' : 9;
//         int ans = 0;
//         for(int i = 0 ; i<= limit ; i++){
//             int updCount = (i == 1) ? count + 1 : count;
//             ans += solve(idx+1,tight && i == s[idx]-'0',updCount,s);
//         }

//         return dp[idx][tight][count] = ans;
//     }
//     int countDigitOne(int n) {
//         memset(dp,-1,sizeof(dp));
//         string s = to_string(n);
//         return solve(0,1,0,s);
//     }
// };

class Solution {
public:
    int nodes[10][2];
    int count1[10][2];

    vector<int> solve(int idx,bool tight, string & s){
        if(idx == s.size()) return {1,0}; // {remianingNodes,countOf1}

        if(nodes[idx][tight]!=-1 && count1[idx][tight]!=-1) return {nodes[idx][tight],count1[idx][tight]};

        int limit = (tight == 1) ? s[idx]-'0' : 9;
        int totalNodes = 0;
        int count = 0;
        for(int i = 0 ; i<= limit ; i++){
            auto v = solve(idx+1,tight && i == s[idx]-'0',s);
            int remainTotalNodes = v[0];
            int remainCount = v[1];
            if(i == 1){
                count += remainTotalNodes;
            }
            totalNodes+=remainTotalNodes;
            count+=remainCount;
        }
        
        nodes[idx][tight] = totalNodes;
        count1[idx][tight] = count;
        return {totalNodes,count};
    }

    int countDigitOne(int n) {
        memset(nodes,-1,sizeof(nodes));
        memset(count1,-1,sizeof(count1));

        string s = to_string(n);
        auto v = solve(0,1,s);
        return v[1];
    }

};