#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(int idx,vector<string>& arr,set<char>& st,string ds,int & ans){
        if(idx == arr.size()){
            ans = max(ans,(int)ds.size());
            return;
        }

        // take
        bool flag = true;
        string s = arr[idx];
        for(char ch : s){
            if(st.count(ch)){
                flag = false;
                break;
            }
        }
        vector<char> v;
        if(flag){
            bool check = true;
            for(char ch : s){
                if(!st.count(ch)){
                    v.push_back(ch);
                    st.insert(ch);
                }else{
                    check = false;
                    break;
                }
            }
            if(check){
                ds+=s;
                helper(idx+1,arr,st,ds,ans);
                ds.erase(ds.size()-s.size());
                for(char ch : s){
                    st.erase(ch);
                }
            }else{
                for(char x : v){
                    st.erase(x);
                }
            }
        }

        // Not take
        helper(idx+1,arr,st,ds,ans);
    }
    int maxLength(vector<string>& arr) {
        set<char> st;
        string ds="";
        int ans=0;
        helper(0,arr,st,ds,ans);
        return ans;
    }
};