#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         sort(begin(arr),end(arr));
//         arr[0]=1;
//         int n = arr.size();
//         int i = 1;
//         int ans = 1;
//         while(i<n){
//             if(arr[i]-arr[i-1]<=1){
//                 ans = max(ans,arr[i]);
//                 i++;
//             }else{
//                 arr[i] = arr[i-1]+1;
//                 ans = max(ans,arr[i]);;
//                 i++;
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(begin(arr),end(arr));
        arr[0]=1;
        int n = arr.size();
        int i = 1;
        int ans = 1;
        while(i<n){
            if(arr[i]-arr[i-1]>1){
                arr[i] = arr[i-1]+1;
            }
            ans = max(ans,arr[i]);;
            i++;
        }
        return ans;
    }
};