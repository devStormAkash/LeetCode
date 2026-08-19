#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_set<int>> arr(n-k+1);
        int i = 0;
        int j = 0;

        while(j<k){
            arr[0].insert(nums[j]);
            j++;
        }

        j--;

        int p = 1;
        while(j<n){
            i++;
            j++;
            if(j==n) break;
            for(int x = i; x<=j ; x++){
                arr[p].insert(nums[x]);
            }
            p++;
        }

        int ans = -1;
        for(int x : nums){
            bool flag = true;
            int cnt = 0;
            for(auto s : arr){
                if(s.count(x)) cnt++;
            }
            if(cnt == 1){
                ans = max(x,ans);
            }
        }

        return ans;
    }
};