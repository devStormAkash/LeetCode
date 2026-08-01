#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         unordered_set<int> st;
//         vector<int> arr;
//         int n = nums.size();
//         for(int i = 0; i<n ; i++){
//             st.insert(nums[i]);
//         }
//         unordered_set<int> st2;
//         vector<bool> v((1<<11),false);
//         for(int i = 0 ; i<n ; i++){
//             for(int j = i+1; j<n ; j++){
//                 if(!v[nums[i]^nums[j]]){
//                     st2.insert(nums[i]^nums[j]);
//                     v[nums[i]^nums[j]]=true;
//                 }
//             }
//         }

//         unordered_set<int> st3;
//         for(auto x:st){
//             for(auto y:st2){
//                 if(!st.count(x^y)) st3.insert(y^x);
//             }
//         }
//         return st.size()+st3.size();
//     }
// };

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> arr;
        vector<bool> all_same_index((1<<11),false);
        int n = nums.size();
        for(int i = 0; i<n ; i++){
            st.insert(nums[i]);
            all_same_index[nums[i]] = true;
        }
        unordered_set<int> st2;
        vector<bool> v((1<<11),false);
        for(int i = 0 ; i<n ; i++){
            for(int j = i+1; j<n ; j++){
                if(!v[nums[i]^nums[j]]){
                    st2.insert(nums[i]^nums[j]);
                    v[nums[i]^nums[j]]=true;
                }
            }
        }

        unordered_set<int> st3;
        for(auto x:st){
            for(auto y:st2){
                if(!all_same_index[x^y]) st3.insert(y^x);
            }
        }
        return st.size()+st3.size();
    }
};