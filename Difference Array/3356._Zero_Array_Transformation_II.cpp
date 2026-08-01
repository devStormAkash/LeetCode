#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(int k,vector<int> nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> a(n,0);
        for(int i = 0;i<=k ; i++){
            int st = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            a[st] += -1*val;
            if(end+1<n) a[end+1] += val;
        }

        bool flag = true;
        for(int i = 1; i<n ; i++){
            a[i]+=a[i-1];
        }
        for(int i = 0; i<n ; i++){
            nums[i]+=a[i];
            if(nums[i]>0){
                flag = false;
                break;
            }
        }
        return flag;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int k = -1;
        int l = 0;
        int r = queries.size()-1;
        int cnt = count(begin(nums),end(nums),0);
        if(cnt==nums.size()) return 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(isPossible(mid,nums,queries)){
                k = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(k==-1) return -1;
        return k+1;
    }
};