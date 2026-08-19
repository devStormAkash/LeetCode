#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = -100000;
        int currSum = 0;
        int len = 0;
        int start = -1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(currSum==0){
                start = i;
            }
            currSum += nums[i];
            if(currSum>maxSum){
                len = max(len,i-start+1);
                maxSum = max(maxSum,currSum);
            }
            if(currSum <0){
                currSum = 0;
            }
        }
        cout << len;
        return maxSum;
    }
};