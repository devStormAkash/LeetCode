#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();

        int i = 0;
        int j = 0;

        while(j<n){
            int val = nums[j];
            if(mp.count(val)){
                if(mp[val]<k){
                    mp[val]++;
                    ans = max(ans,j-i+1);
                    j++;
                }else{
                    mp[nums[i]]--;
                    i++;
                }
            }else{
                mp[val]++;
                ans = max(ans,j-i+1);
                j++;
            }
        }

        return ans;
    }
};