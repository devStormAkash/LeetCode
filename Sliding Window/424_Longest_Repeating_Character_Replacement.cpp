#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char,int> mp;
        int max_freq = 0;
        int ans = 0;

        while(j<n){
            char ch = s[j];
            mp[ch]+=1;
            max_freq = max(max_freq,mp[ch]);
            int len = j-i+1;
            if(len-max_freq<=k){
                ans = max(ans,len);
                j++;
            }else{
                mp[s[i]]-=1;
                mp[s[j]]-=1;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                for(auto it : mp){
                    max_freq = max(max_freq,it.second);
                }
                i++;
            }
        }

        return ans;
    }
};