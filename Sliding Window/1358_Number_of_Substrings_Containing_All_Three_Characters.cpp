#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<char,int> mp;
        int n = s.size();

        while(j<n){
            char ch = s[j];
            mp[ch]+=1;
            while(i<n && mp.size()==3){
                ans += (n-j);
                char c = s[i];
                mp[c]--;
                if(mp[c]==0){
                    mp.erase(c);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};