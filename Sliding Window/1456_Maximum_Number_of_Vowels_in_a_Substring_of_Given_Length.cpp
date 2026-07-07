#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> mp;
        int i = 0, j = 0;
        while(j<n){
            char ch = s[j];
            if(isVowel(ch)) mp[ch]+=1;

            while(j<n && j-i+1==k){
                int sum = 0;
                for(auto it : mp){
                    sum+=it.second;
                }
                ans = max(ans,sum);
                char c = s[i];
                if(isVowel(c)){
                    mp[c]--;
                    if(mp[c]==0) mp.erase(c);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};