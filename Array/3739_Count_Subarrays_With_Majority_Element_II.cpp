#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        long long cumSum = 0;
        long long validLeftCount = 0;
        long long result = 0;
        for(int i = 0; i<n ; i++){
            if(nums[i] == target){
                validLeftCount+=mp[cumSum];
                cumSum+=1;
            }else{
                cumSum-=1;
                validLeftCount-=mp[cumSum];
            }
            result+=validLeftCount;
            mp[cumSum]+=1;
        }
        return result;
    }
};