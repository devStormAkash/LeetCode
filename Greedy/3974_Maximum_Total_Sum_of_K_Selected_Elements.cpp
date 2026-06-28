#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<ll> arr;
        for(int i = n-k; i<n ; i++){
            arr.push_back((ll)nums[i]);
        }
        ll ans = 0;
        for(int i = arr.size()-1 ; i>=0 ; i--){
            if(mul>0){
                ans += (arr[i]*(ll)mul);
                mul--;
            }else{
                ans+=arr[i];
            }
        }

        return ans;
    }
};