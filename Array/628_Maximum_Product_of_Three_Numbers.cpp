#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        sort(begin(nums),end(nums));
        int p = 0;
        int n = 0;
        for(int x : nums){
            if(x<0) n++;
            if(x>=0) p++;
        }
        
        if(n==size || size == 3 || p==size) return nums[size-1]*nums[size-2]*nums[size-3];
        int ans = INT_MIN;
        if(n>=2){
            ans = max(ans,nums[0]*nums[1]*nums[size-1]);
        }
        if(p>=3){
            ans = max(ans,nums[size-1]*nums[size-2]*nums[size-3]);
        }
        return ans;
    }
};
