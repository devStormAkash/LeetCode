#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums){
        ll n = nums.size();
        ll ans = 0;
        ll last_big = nums[n-1];
        for(ll i = n-2 ; i>=0 ; i--){
            if(nums[i]<=last_big){
                last_big = nums[i];
                continue;
            }

            if(nums[i]%last_big == 0){
                ans += (nums[i]/last_big)-1;
            }else{
                ll buckets = nums[i]/last_big;
                buckets++;
                ans += buckets-1;
                last_big = nums[i]/buckets;
            }
        }
        return ans;
    }
};