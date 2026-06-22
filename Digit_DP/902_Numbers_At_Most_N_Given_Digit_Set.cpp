#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     unordered_map<string,int> mp;
//     int solve(int idx, string & num, int & n, int & max_val,vector<string>& digits){
//         if(idx == n){
//             // cout << num << endl;
//             long long val = stol(num);
//             return val<=max_val;
//         }
//         string s = to_string(idx) + '#' + num + '#' + to_string(n);
//         if(mp.count(s)) return mp[s];

//         int ans = 0;
//         for(int i = 0 ; i<digits.size() ; i++){
//             num+=digits[i];
//             ans += solve(idx+1,num,n,max_val,digits);
//             num.pop_back();
//         }
//         return mp[s] = ans;
//     }

//     int atMostNGivenDigitSet(vector<string>& digits, int n) {
//         int size = (int)log10(n)+1;
//         string num = "";
//         // return solve(0,num,size,n,digits);
//         int ans = 0;
//         for(int i = 1; i<=size ; i++){
//             num = "";
//             ans += solve(0,num,i,n,digits);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     unordered_map<string,int> mp;
//     int solve(int idx, string & num, int & n, int & max_val,vector<string>& digits){
//         if(idx == n){
//             // cout << num << endl;
//             long long val = stol(num);
//             return val<=max_val;
//         }
//         string s = to_string(idx) + '#' + num + '#' + to_string(n);
//         if(mp.count(s)) return mp[s];
        
//         int ans = 0;
//         for(int i = 0 ; i<digits.size() ; i++){
//             num+=digits[i];
//             ans += solve(idx+1,num,n,max_val,digits);
//             num.pop_back();
//         }
//         return mp[s] = ans;
//     }

//     int atMostNGivenDigitSet(vector<string>& digits, int n) {
//         int size = (int)log10(n)+1;
//         string num = "";
//         // return solve(0,num,size,n,digits);
//         int ans = 0;
//         int m = digits.size();
//         for(int k = 1 ; k<size ; k++){
//             ans += (int)pow(m,k);
//         }
//         ans += solve(0,num,size,n,digits);
//         return ans;
//     }
// };


class Solution {
public:
    int dp[12][2];
    int solve(int idx,bool tight, string & s,vector<string>& digits){
        if(idx == s.size()) return 1;
        if(dp[idx][tight] != -1) return dp[idx][tight];

        int ans = 0;
        int limit = (tight == 1) ? s[idx]-'0' : 9;
        for(int i = 0 ; i<digits.size(); i++){
            int val = stoi(digits[i]);
            if(val<=limit){
                ans += solve(idx+1,tight && val == s[idx]-'0',s,digits);
            }
        }
        return dp[idx][tight] = ans;
    }

    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        memset(dp,-1,sizeof(dp));
        int size = (int)log10(n)+1;
        string num = "";
        int ans = 0;
        int m = digits.size();
        for(int k = 1 ; k<size ; k++){
            ans += (int)pow(m,k);
        }
        string s = to_string(n);
        ans += solve(0,1,s,digits);
        return ans;
    }
};