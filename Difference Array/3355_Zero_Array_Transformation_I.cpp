#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> a(n,0);
        for(auto it : queries){
            int st = it[0];
            int end = it[1];
            a[st] += -1;
            if(end+1<n) a[end+1] += 1;
        }
        for(int i = 1; i<n ; i++){
            a[i]+=a[i-1];
        }

        for(int i = 0; i<n ; i++){
            nums[i]+=a[i];
        }

        bool flag = true;
        for(int i = 0; i<n ; i++){
            if(nums[i]>0){
                flag = false;
                break;
            }
        }
        return flag;
    }
};