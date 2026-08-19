#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int fn(int i , int j,string & s1, string & s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = fn(i-1,j-1,s1,s2);
        }else{
            return dp[i][j] = 1 + min({fn(i,j-1,s1,s2),fn(i-1,j,s1,s2),fn(i-1,j-1,s1,s2)});
        }
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return fn(word1.size()-1,word2.size()-1,word1,word2);
    }
};