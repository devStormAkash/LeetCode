#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int leftmost = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                leftmost = mid;
                r = mid-1;
            }else if(target<nums[mid]){
                r = mid-1;
            }else if(target>nums[mid]){
                l = mid+1;
            }
        }

        l = 0;
        r = n-1;
        int rightmost = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] == target){
                rightmost = mid;
                l = mid+1;
            }else if(target<nums[mid]){
                r = mid-1;
            }else if(target>nums[mid]){
                l = mid+1;
            }
        }

        return {leftmost,rightmost};
    }
};