#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int,int> mp; // map of index to bit reprenetation of string
        for(int i = 0; i<n ; i++){
            int mask = 0;
            for(char ch : words[i]){
                mask = mask | (1<<(ch-'a'));
            }
            mp[i] = mask;
        }
        
        int ans = 0;
        for(int i = 0; i<n ; i++){
            for(int j = i+1; j<n ; j++){
                if(mp[i]&mp[j]) continue;
                ans = max(ans,(int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};