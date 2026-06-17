#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n = nums.size();
        ll ans = LONG_MIN;
        for(int mask = 0; mask < (1<<n) ; mask++){
            ll mul = 1;
            for(int i = 0;i<n ; i++){
                if(mask&(1<<i)){
                    mul*=nums[i];
                }
            }
            if(mask!=0) ans = max(ans,mul);
        }
        return ans;
    }
};