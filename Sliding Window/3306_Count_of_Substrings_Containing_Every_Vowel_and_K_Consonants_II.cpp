#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    bool isVowel(char & ch){
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
    }
    long long countOfSubstrings(string word, int k) {
        ll ans = 0;
        unordered_map<char,int> mp;
        int n = word.size();
        // Build the array to store the index of next consonat
        int nc = n;
        vector<int> nextConsonant(n);
        for(int i = n-1; i>=0 ; i--){
            nextConsonant[i] = nc;
            if(!isVowel(word[i])){
                nc = i;
            }
        }

        int i = 0;
        int j = 0;
        int consonant = 0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                consonant++;
            }

            while(consonant>k){
                char c = word[i];
                if(isVowel(c)){
                    mp[c]--;
                    if(mp[c]==0) mp.erase(c);
                }else{
                    consonant--;
                }
                i++;
            }

            while(mp.size()==5 && consonant == k){
                int idx = nextConsonant[j];
                ans += (idx-j);
                char c = word[i];
                if(isVowel(c)){
                    mp[c]--;
                    if(mp[c]==0) mp.erase(c);
                }else{
                    consonant--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};