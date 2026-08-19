#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int fn(int i , int j, string & s1 , string & s2){
        if(i < 0){
            if(j<0) return 1;
            else return 0;
        }
        if(j<0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]){
            return dp[i][j] = fn(i-1,j-1,s1,s2) + fn(i-1,j,s1,s2);
        }else return dp[i][j] = fn(i-1,j,s1,s2);
    }

    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n1 = s.size();
        int n2 = t.size();
        return fn(n1-1,n2-1,s,t);
    }
};