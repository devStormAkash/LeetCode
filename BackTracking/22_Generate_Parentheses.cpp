#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int idx,int openBrace, int n,string &path,stack<char> &st,vector<string> &ans){
        if(openBrace > n){
            return;
        }
        if(idx == 2*n){
            if(path.size() == 2*n ) ans.push_back(path);
            return;
        }
        path+="(";
        st.push('(');
        helper(idx+1,openBrace+1,n,path,st,ans);
        path.pop_back();
        st.pop();
        if(st.empty()) return;
        else if(st.top() == '('){
            st.pop();
            path+=")";
            helper(idx+1,openBrace,n,path,st,ans);
            path.pop_back();
            st.push('(');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        stack<char> st;
        string path = "";
        helper(0,0,n,path,st,ans);
        return ans;
    }
};