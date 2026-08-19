#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cum_sum = 0;
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i<n ; i++){
            cum_sum+=nums[i];
            int sum_from_start = cum_sum - k;
            if(mp.count(sum_from_start)){
                ans+=mp[sum_from_start];
            }
            mp[cum_sum]+=1;
        }

        return ans;
    }
};