#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i<k ; i++){
            mp[nums[i]]+=1;
        }
        int i = 0;
        int j = k-1;
        vector<int> ans;

        while(j<n){
            auto it = mp.rbegin();
            ans.push_back(it->first);
            j++;
            if(j>=n) break;
            mp[nums[j]]+=1;
            mp[nums[i]]-=1;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }
        return ans;
    }
};