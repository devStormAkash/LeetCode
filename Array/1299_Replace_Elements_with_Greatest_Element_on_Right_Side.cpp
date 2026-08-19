#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int ans = -1;
        int n = arr.size();
        for(int i = n-1 ; i>=0 ; i--){
            if(arr[i]>ans){
                int temp = arr[i];
                arr[i] = ans;
                ans = temp;
            }else{
                arr[i] = ans;
            }
        }
        return arr;
    }
};