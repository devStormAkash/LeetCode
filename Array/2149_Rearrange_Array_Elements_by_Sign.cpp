#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = 1;
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i<n ; i++){
            if(nums[i]>0){
                ans[ptr1] = nums[i];
                ptr1+=2;
            }else{
                ans[ptr2] = nums[i];
                ptr2+=2;
            }
        }
        return ans;
    }
};