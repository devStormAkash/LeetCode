#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(target<nums[mid]){
                r = mid-1;
            }else if(target>nums[mid]){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return l;// Here we reached when l>r means l crossed r and by paper work we seen that l reached to the correct insert place
    }
};
