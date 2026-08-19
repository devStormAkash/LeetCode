#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int lcs(int i, int j, string & word1, string & word2){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]){
            return dp[i][j] = 1+lcs(i-1,j-1,word1,word2);
        }else{
            return dp[i][j] = max(lcs(i-1,j,word1,word2),lcs(i,j-1,word1,word2));
        }
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int m = word1.size();
        int n = word2.size();

        return m+n - 2*lcs(m-1,n-1,word1,word2);
    }
};