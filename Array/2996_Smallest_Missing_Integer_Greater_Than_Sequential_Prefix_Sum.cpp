#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int p = 0;
        int n = nums.size();
        if(n==1) return nums[0]+1;
        int i = 1;
        while(i<n&&nums[i]==nums[i-1]+1){
            p=i;
            i++;
        }

        int sum = 0;
        for(int j = 0; j<=p ; j++){
            sum+=nums[j];
        }

        unordered_set<int> st;
        for(int j = 0; j<n ; j++){
            st.insert(nums[j]);
        }

        int ans = sum;
        while(st.count(ans)){
            ans++;
        }

        return ans;
    }
};





ll count_ways(int parity, int n, string &s) {
    bool match_pattern_0 = true;
    bool match_pattern_1 = true;
 
    for (int i = parity; i < n; i += 2) {
        if (s[i] == '?') continue;
 
        int step = (i - parity) / 2;
        char expected_0 = (step % 2 == 0) ? '0' : '1';
        char expected_1 = (step % 2 == 0) ? '1' : '0';
 
        if (s[i] != expected_0) match_pattern_0 = false;
        if (s[i] != expected_1) match_pattern_1 = false;
    }
 
    ll ways = 0;
    if (match_pattern_0) ways++;
    if (match_pattern_1) ways++;
 
    return ways;
}
 
void solve() {
    int n;
    cin >> n;
 
    string s;
    cin >> s;
 
    ll even_ways = count_ways(0, n, s);
    ll odd_ways = count_ways(1, n, s);
 
    ll total_ways = (even_ways * odd_ways) % 998244353;
 
    cout << total_ways << "\n";
}