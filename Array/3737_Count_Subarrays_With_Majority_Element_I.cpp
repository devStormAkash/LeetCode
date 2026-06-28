#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target){
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0 ; i<n ; i++){
//             int count = 0;
//             for(int j = i; j<n; j++){
//                 if(target == nums[j]) count++;
//                 int size = j-i+1;
//                 if(count>=(size/2+1)){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target){
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0 ; i<n ; i++){
//             int count = 0;
//             for(int j = i; j<n; j++){
//                 if(target == nums[j]) count++;
//                 else count--;
//                 if(count>0){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target){
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int cumSum = 0;
        int validLeftCount = 0;
        int result = 0;
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