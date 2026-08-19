#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int lcs(int i, int j,string & s1, string & s2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = 1+lcs(i-1,j-1,s1,s2);
        }else{
            return dp[i][j] = max(lcs(i-1,j,s1,s2),lcs(i,j-1,s1,s2));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string rev = s;
        reverse(begin(rev),end(rev));
        int n = s.size();
        return lcs(n-1,n-1,s,rev);
    }
};