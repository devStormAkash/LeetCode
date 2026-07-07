#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(2*k+1>n) return ans;
        int i = 0;
        int j = 0;
        ll sum = 0;
        while(j<n){
            sum+=nums[j];
            if(j<n && j-i+1 == 2*k+1){
                int idx = (j+i)/2;
                ans[idx] = sum/(2*k+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};