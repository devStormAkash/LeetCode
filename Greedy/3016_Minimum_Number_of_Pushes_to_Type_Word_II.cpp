#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(auto ch : word){
            mp[ch]+=1;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        unordered_map<char,int> no_of_pushes;
        int count = 0;
        while(!pq.empty()){
            auto [freq , ch] = pq.top();
            pq.pop();
            int pushes = (count/8)+1;
            no_of_pushes[ch]=pushes;
            count++;
        }

        int min_pushes = 0;
        for(auto ch : word){
            min_pushes+=no_of_pushes[ch];
        }
        return min_pushes;
    }
};