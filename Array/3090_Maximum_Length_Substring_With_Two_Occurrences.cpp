#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> mp;

        while(j<n){
            char ch = s[j];
            if(mp.count(ch)){
                if(mp[ch]<2){
                    mp[ch]++;
                    ans = max(ans,j-i+1);
                    j++;
                }else{
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }else{
                mp[ch]++;
                ans = max(ans,j-i+1);
                j++;
            }
        }

        return ans;
    }
};