#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
// class Solution {
// public:
//     ll lcs(ll i,ll j,string& s1, string& s2,vector<vector<ll>>& dp){
//         if(i<0 || j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         // match 
//         if(s1[i]==s2[j]) return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2,dp);
//         // not match
//         return dp[i][j] = 0 + max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         ll m = text1.size();
//         ll n = text2.size();
//         vector<vector<ll>> dp(m,vector<ll>(n,-1));
//         return lcs(m-1,n-1,text1,text2,dp);
//     }
// };


// shift indices (-1 to n-1) to (0 to n)
// using ll = long long;
// class Solution {
// public:
//     ll lcs(ll i,ll j,string& s1, string& s2,vector<vector<ll>>& dp){
//         if(i==0 || j==0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         // match 
//         if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2,dp);
//         // not match
//         return dp[i][j] = 0 + max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         ll m = text1.size();
//         ll n = text2.size();
//         vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
//         return lcs(m,n,text1,text2,dp);
//     }
// };




// Tabulation

// using ll = long long;
// class Solution {
// public:
//     ll lcs(ll i,ll j,string& s1, string& s2,vector<vector<ll>>& dp){
//         if(i==0 || j==0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         // match 
//         if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2,dp);
//         // not match
//         return dp[i][j] = 0 + max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         ll m = text1.size();
//         ll n = text2.size();
//         vector<vector<ll>> dp(m+1,vector<ll>(n+1,-1));
//         for(ll i = 0;i<=m; i++) dp[i][0] = 0;
//         for(ll i = 0;i<=n; i++) dp[0][i] = 0;

//         for(ll i = 1; i<=m ; i++){
//             for(ll j = 1; j<=n ; j++){
//                 // match 
//                 if(text1[i-1]==text2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
//                 // not match
//                 else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[m][n];
//     }
// };


// space optimization
using ll = long long;
class Solution {
public:
    ll lcs(ll i,ll j,string& s1, string& s2,vector<vector<ll>>& dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // match 
        if(s1[i-1]==s2[j-1]) return dp[i][j] = 1 + lcs(i-1,j-1,s1,s2,dp);
        // not match
        return dp[i][j] = 0 + max(lcs(i-1,j,s1,s2,dp),lcs(i,j-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        ll m = text1.size();
        ll n = text2.size();
        vector<ll> prev(n+1,0),curr(n+1,0);

        for(ll i = 1; i<=m ; i++){
            for(ll j = 1; j<=n ; j++){
                // match 
                if(text1[i-1]==text2[j-1])  curr[j] = 1 + prev[j-1];
                // not match
                else curr[j] = 0 + max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return curr[n];
    }
};