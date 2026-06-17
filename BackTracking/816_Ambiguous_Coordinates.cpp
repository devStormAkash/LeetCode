#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    vector<string> symb = {", ","."};
    void helper(int idx,string& s,vector<string> & ds,vector<vector<string>>& ans){
        if(idx == s.size()){
            if(ds.size()==2) ans.push_back(ds);
            return;
        }
        for(int i = idx ; i<s.size() ; i++){
            string str = s.substr(idx,i-idx+1);
            ds.push_back(str);
            helper(i+1,s,ds,ans);
            ds.pop_back();
        }
    }

    vector<string> place_dot(string& s){
        vector<string> ans;
        for(int i = 0 ; i<s.size()-1 ; i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1);
            if(s2[s2.size()-1]=='0') break;
            if(s1.size()==2 && s1[0]=='0') break;
            ans.push_back(s1+'.'+s2);
        }
        return ans;
    }

    vector<string> ambiguousCoordinates(string s) {
        s.pop_back();
        s = s.substr(1);
        vector<string> ds;
        vector<vector<string>> possible_split;
        helper(0,s,ds,possible_split);
        // for(auto x : possible_split){
        //     cout << x[0] << " " << x[1] << endl;
        // }
        // vector<string> a = place_dot(possible_split[0][1]);
        // for(auto x : a){
        //     cout << x << endl;
        // }
        vector<string> ans;
        for(int i = 0; i<possible_split.size() ; i++){
            vector<string> v = possible_split[i];
            string s1 = v[0];
            string s2 = v[1];
            vector<string> arr1 = place_dot(s1);
            vector<string> arr2 = place_dot(s2);
            if(s1.size()<2 || (s1.size()>=2 && s1[0]!='0')){
                arr1.push_back(s1);
            }
            if(s2.size()<2 || s2.size()>=2 && s2[0]!='0'){
                arr2.push_back(s2);
            }
            if(!arr1.empty() && !arr2.empty()){
                int m = arr1.size();
                int n = arr2.size();
                for(int j = 0 ; j<m ; j++){
                    string sub1 = arr1[j];
                    for(int k = 0 ; k<n ; k++){
                        string sub2 = arr2[k];
                        ans.push_back('('+sub1+", "+sub2+')');
                    }
                }
            }
        }

        return ans;
    }
};