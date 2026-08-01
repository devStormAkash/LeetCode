#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty()) return s;
        string str = s;
        reverse(begin(s),end(s));
        s = str+'#'+s;
        int n = s.size();

        // Build LPS KMP algo
        vector<int> lps(n);
        int len = 0;
        int i = 1;
        lps[0] = len;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        string str_to_add = str.substr(lps[n-1]);
        reverse(begin(str_to_add),end(str_to_add));
        string ans = str_to_add+str;
        return ans;
    }
};