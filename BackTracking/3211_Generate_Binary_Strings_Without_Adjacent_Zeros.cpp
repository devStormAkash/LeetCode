#include <iostream>
#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    void helper(int idx, int prev ,int n, string & path , vector<string>& ans){
        if(idx==n){
            ans.push_back(path);
            return;
        }
        // add '0' to path and backtrack
        if(prev == -1 || (prev!=-1 && path[prev]!='0')){
            path+='0';
            helper(idx+1,idx,n,path,ans);
            path.pop_back();
        }

        // add '1' to path and backtrack
        path+='1';
        helper(idx+1,idx,n,path,ans);
        path.pop_back();
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string path = "";
        helper(0,-1,n,path,ans);
        return ans;
    }
};