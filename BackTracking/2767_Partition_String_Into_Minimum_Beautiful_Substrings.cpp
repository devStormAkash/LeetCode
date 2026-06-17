#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
class Solution {
public:
    bool isPowerOf5(ll n){
        if(n<1) return false;
        while(n%5==0){
            n/=5;
        }
        return n == 1;
    }

    int ans = INT_MAX;;
    void helper(int idx,string& s, vector<string> & ds){
        if(idx == s.size()){
            ans = min(ans,(int)ds.size());
            return;
        }
        for(int i = idx; i<s.size() ; i++){
            string sub = s.substr(idx,i-idx+1);
            if(sub[0]=='0') break;
            int val = stoi(sub,nullptr,2);
            if(isPowerOf5(val)){
                ds.push_back(sub);
                helper(i+1,s,ds);
                ds.pop_back();
            }
        }
    }

    int minimumBeautifulSubstrings(string s) {
        vector<string> ds;
        helper(0,s,ds);
        return ans==INT_MAX?-1:ans;
    }
};