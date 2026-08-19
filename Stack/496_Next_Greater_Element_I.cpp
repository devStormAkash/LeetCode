#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_greater(vector<int>& arr){
        int n = arr.size();
        vector<int> nge(n,0);
        stack<int> st;
        for(int i = n-1; i>=0 ; i--){
            while(!st.empty() && arr[i]>=st.top()){
                st.pop();
            }
            nge[i] = (st.empty()? -1 : st.top());
            st.push(arr[i]);
        }
        return nge;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        for(int i = 0; i<nums2.size() ; i++){
            mp[nums2[i]] = i;
        }

        vector<int> nge = next_greater(nums2);
        vector<int> ans(n);
        for(int i = 0; i<n ; i++){
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};