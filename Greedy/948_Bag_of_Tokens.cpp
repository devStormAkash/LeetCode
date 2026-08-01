#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n==0) return 0;
        sort(begin(tokens),end(tokens));
        int i = 0;
        int j = n-1;
        int ans = 0;
        int score = 0;
        if(tokens[0]>power) return 0;
        if(n==1){
            if(power>=tokens[0]) return 1;
        }
        while(i<j){
            while(i<n&&power>=tokens[i]){
                power-=tokens[i];
                score++;
                i++;
                ans = max(ans,score);
            }
            if(i<n&&j>=0&&power<tokens[i] && score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
        }
        
        return ans;
    }
};