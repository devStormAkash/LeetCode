#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int maxi  = *max_element(begin(nums),end(nums));
        int n = nums.size();
        int d = 0;
        int temp = maxi;
        while(temp!=0){
            d++;
            temp = temp>>1;
        }

        bool is_all_even = true;
        bool is_all_zero = true;
        for(int i  = 0 ; i<d ; i++){
            int cnt = 0;
            for(int j = 0; j<n ; j++){
                if((nums[j]&(1<<i))!=0) cnt++;
                if(nums[j]!=0) is_all_zero = false;
            }
            if(cnt%2==1){
                is_all_even = false;
                break;
            }
        }

        if(is_all_zero) return 0;
        return is_all_even?n-1:n;
    }
};