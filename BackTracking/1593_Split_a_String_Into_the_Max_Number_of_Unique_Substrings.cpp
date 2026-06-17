#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(int idx,string& s,set<string>& st,int & ans){
        if(idx == s.size()){
            ans = max(ans,(int)st.size());
            return;
        }
        for(int i = idx;i<s.size() ; i++){
            string str = s.substr(idx,i-idx+1);
            if(st.count(str)) continue;
            st.insert(str);
            // ds.push_back(str);
            helper(i+1,s,st,ans);
            // ds.pop_back();
            st.erase(str);
        }

    }
    int maxUniqueSplit(string s) {
        set<string> st;
        // vector<string>  ds;
        int ans = 0;
        helper(0,s,st,ans);
        return ans;
    }
};