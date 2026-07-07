#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digit_range(string & s){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(char ch : s){
            mini = min(mini,ch-'0');
            maxi = max(maxi,ch-'0');
        }
        return maxi-mini;
    }
    
    int maxDigitRange(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int x : nums){
            string s = to_string(x);
            int range = digit_range(s);
            mp[range].push_back(x);
        }
        auto it = *(mp.rbegin());
        vector<int> v = it.second;
        int ans = accumulate(begin(v),end(v),0);
        return ans;
    }
};