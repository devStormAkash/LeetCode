#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    map<int,int> mp; // stores (or value : frequency)
    void helper(int idx , vector<int>& nums , int or_val){
        if(idx == nums.size()){
            mp[or_val]+=1;
            return;
        }
        // take
        int temp = or_val;
        if(temp==-1) temp = nums[idx];
        else temp |= nums[idx];
        helper(idx+1,nums,temp);

        // not take
        helper(idx+1,nums,or_val);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> ds;
        helper(0,nums,-1);
        auto last = mp.rbegin();
        return last->second;
    }
};