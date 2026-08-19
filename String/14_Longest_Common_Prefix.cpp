#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = INT_MAX;
        for(auto s : strs){
            n = min(n,(int)s.size());
        }
        cout << n;
        string ans = "";
        for(int i = 0 ; i<n ; i++){
            char ch = strs[0][i];
            for(auto s : strs){
                if(ch!=s[i]){
                    return ans;
                }
            }
            ans.push_back(ch);
        }
        return ans;
    }
};