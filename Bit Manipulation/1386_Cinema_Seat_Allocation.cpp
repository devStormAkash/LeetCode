#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto it : reservedSeats){
            int u = it[0];
            int v = it[1];
            mp[u].insert(v);
        }

        for(auto it = mp.begin(); it != mp.end(); ) {
            auto &s = it->second;
            if(s.size() == 2 && s.count(1) && s.count(10)) {
                it = mp.erase(it);
            } else {
                ++it;
            }
        }

        int blocks = 0;
        int rem = n - mp.size();
        for(auto it : mp){
            int mask = 0;
            auto & s = it.second;
            if(s.count(2) || s.count(3)){
                mask|=(1<<3);
            }
            if(s.count(4) || s.count(5)){
                mask|=(1<<2);
            }
            if(s.count(6) || s.count(7)){
                mask|=(1<<1);
            }
            if(s.count(8) || s.count(9)){
                mask|=(1<<0);
            }

            if(mask == 5 || mask == 6 || mask == 7 || mask == 10 || mask == 11 || mask == 13 || mask == 14 || mask == 15){
                blocks += 0;
            }else if(mask == 1 || mask == 2 || mask == 3 || mask == 4 || mask == 8 || mask == 9 || mask == 12){
                blocks += 1;
            }else{
                blocks += 2;
            }
        }

        blocks += rem*2;

        return blocks;

    }
};