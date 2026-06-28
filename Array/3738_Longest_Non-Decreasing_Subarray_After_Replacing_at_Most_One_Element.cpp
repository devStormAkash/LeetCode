#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        // in this array we store the first and last indexes of every consecutive incresing blocks , now drw the incresing blocks side by side on the paper then you can do it by yourself
        vector<pair<int,int>> arr;
        int i = 0; 
        while(i<n){
            vector<int> v;
            int p1 = i;
            int j = i;
            int p2;
            while(j<n && (v.empty() || nums[j]>=v.back())){
                v.push_back(nums[j]);
                p2 = j;
                j++;
            }
            i = j;
            arr.push_back({p1,p2});
        }

        int ans = 0;
        for(int i = 0; i<arr.size()-1 ; i++){
            int curr_i = arr[i].first;
            int curr_j = arr[i].second;
            int next_i = arr[i+1].first;
            int next_j = arr[i+1].second;
            ans = max(ans,curr_j-curr_i+1);
            if(next_i+1<n && nums[next_i+1]>=nums[curr_j]){
                ans = max(ans,next_j-curr_i+1);
            }else{
                ans = max(ans,curr_j-curr_i+1+1);
            }
        }
        // cout << ans;
        for(int i = arr.size()-1; i>=1 ; i--){
            int curr_i = arr[i].first;
            int curr_j = arr[i].second;
            int prev_i = arr[i-1].first;
            int prev_j = arr[i-1].second;
            ans = max(ans,curr_j-curr_i+1);
            if(prev_j-1>=0 && nums[prev_j-1]<=nums[curr_i]){
                ans = max(ans,curr_j-prev_i+1);
            }else{
                ans = max(ans,curr_j-curr_i+1+1);
            }
        }
        if(arr.size()==1) ans = max(ans,arr[0].second-arr[0].first+1);
        return ans;
    }
};