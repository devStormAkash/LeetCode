#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    bool canBePartitioned(int idx, string& num , int k , int curr_sum){
        if(idx == num.size()){
            if(curr_sum == k) return true;
            return false;
        }
        for(int i = idx ; i<num.size() ; i++){
            string s = num.substr(idx,i-idx+1);
            int val = stoi(s);
            if(canBePartitioned(i+1,num,k,curr_sum+val)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1; i<=n ; i++){
            string num = to_string(i*i);
            if(canBePartitioned(0,num,i,0)) sum+=(i*i);
        }
        return sum;
    }
};