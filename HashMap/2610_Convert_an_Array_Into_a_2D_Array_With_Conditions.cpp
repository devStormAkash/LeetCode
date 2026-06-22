#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = 0;
        for(int x : nums){
            mp[x]++;
            n = max(n,mp[x]);
        }

        vector<vector<int>> ans(n);
        for(auto it : mp){
            int x = it.second;
            int num = it.first;
            for(int i = 0 ; i<x ; i++){
                ans[i].push_back(num);
            }
        }

        return ans;

    }
};