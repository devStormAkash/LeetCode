#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(char ch : text){
            mp[ch]+=1;
        }
        string s = "balloon";
        int ans = INT_MAX;
        for(char ch : s){
            if(!mp.count(ch)) return 0;
            if((ch == 'o' || ch == 'l') && mp[ch]<2) return 0;
            int x = (ch == 'o' || ch == 'l') ? mp[ch]/2:mp[ch];
            ans = min(ans,x);
        }
        return ans;
    }
};