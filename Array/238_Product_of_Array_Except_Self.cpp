#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n =  nums.size();
        int val = 1;
        int val_zero = 1;
        int zero = 0;
        int zero_idx = -1;

        for(int i = 0; i<n ; i++){
            if(nums[i]==0){
                zero++;
                zero_idx = i;
            }
            if(nums[i]!=0) val_zero*=nums[i];
            val*=nums[i];
        }
        
        vector<int> ans(n,0);

        if(zero == 1){
            ans[zero_idx] = val_zero;
            return ans;
        }else if(zero>1){
            return ans;
        }
        

        for (int i = 0; i < nums.size(); i++) {
            ans[i] = (val / nums[i]);
        }
        return ans;
    }
};    