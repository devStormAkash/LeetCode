#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<ll,ll> mp;
        vector<int> arr1 = arr;
        sort(begin(arr),end(arr));
        ll rank = 1;
        ll n = arr.size();
        for(ll i = 0; i<n ; i++){
            if(i==0) mp[arr[i]] = rank;
            else{
                if(arr[i]!=arr[i-1]) rank++;
                mp[arr[i]] = rank;
            }
        }
        vector<int> ans(n);
        for(ll i = 0; i<n ; i++){
            ans[i] = mp[arr1[i]];
        }
        return ans;
    }
};