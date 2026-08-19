#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         unordered_map<string,int> mp;
//         for(auto word : words){
//             mp[word]+=1;
//         }

//         int n = s.size();
//         int sz = words[0].size()*words.size();
//         vector<int> ans;
//         int i = 0;
//         while(i<=n-sz){
//             unordered_map<string,int> curr_mp;

//             for(int j=i;j<i+sz;j+=words[0].size()){
//                 string word = s.substr(j, words[0].size());
//                 if(!mp.count(word)){
//                     curr_mp.clear();
//                     break;
//                 }
//                 curr_mp[word]++;
//             }

//             bool flag = true;
//             for(auto it : curr_mp){
//                 if(mp[it.first]!=it.second){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag&&mp.size()==curr_mp.size()){
//                 ans.push_back(i);
//                 // i+=words[0].size();
//             }
//             // else i++;
//             i++;            
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // build the map to keep track of words
        unordered_map<string,int> mp;
        for(auto word : words){
            mp[word]+=1;
        }

        int n = s.size();
        int sz = words[0].size()*words.size();
        vector<int> ans;
        // Edge case: string is smaller than total required length
        if (n < sz) return ans;
        
        int n2 = words[0].size();
        // FIX: Add an offset loop so we don't miss indices 1, 2, etc.
        for (int offset = 0; offset < n2; ++offset) {
            
            unordered_map<string,int> curr_mp;
            int count = 0;
            
            // Check if initial window setup goes out of bounds
            if (offset + sz > n) continue;

            // Check with sliding window if index 'offset' is a valid candidate or not
            for(int k = offset; k < offset + sz; k += n2){
                string word = s.substr(k, n2);
                if(mp.count(word)){
                    curr_mp[word]+=1;
                    count++;
                }
            }

            if(count == words.size() && mp.size()==curr_mp.size()){
                bool flag = 1;
                for(auto it : curr_mp){
                    if(mp[it.first]!=it.second){
                        flag = false;
                        break;
                    }
                }
                if(flag) ans.push_back(offset);
            }

            // Slide the window for this specific offset
            int i = offset;
            int j = offset + sz;
            while(j <= n - n2){

                string word = s.substr(j, n2);
                if(mp.count(word)){
                    count++;
                    curr_mp[word]+=1;
                }

                word = s.substr(i, n2);
                if(mp.count(word) && curr_mp.count(word)){
                    count--;
                    curr_mp[word]-=1;
                    if(curr_mp[word]==0) curr_mp.erase(word);
                }
                
                i += n2;
                j += n2;
                
                if(count == words.size() && mp.size()==curr_mp.size()){
                    bool flag = 1;
                    for(auto it : curr_mp){
                        if(mp[it.first]!=it.second){
                            flag = false;
                            break;
                        }
                    }
                    if(flag) ans.push_back(i);
                }
            }
        }
        return ans;
    }
};