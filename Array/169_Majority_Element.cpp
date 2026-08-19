#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int last_val;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            if(cnt == 0){
                last_val = nums[i];
            }
            if(nums[i]==last_val){
                cnt++;
            }else{
                cnt--;
            }
        }
        return last_val;
    }
};