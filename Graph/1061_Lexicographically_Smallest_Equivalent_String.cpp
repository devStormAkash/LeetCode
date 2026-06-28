#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(char node ,char par, string & s,unordered_map<char,vector<char>>& mp,unordered_set<char>& vis){
        s+=node;
        vis.insert(node);
        for(auto child : mp[node]){
           if(!vis.count(child))dfs(child,node,s,mp,vis);
        }
        // vis.erase(node);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        unordered_map<char,vector<char>> mp;
        for(int i = 0 ; i<s1.size() ; i++){
            if(s1[i]==s2[i]) continue;
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string ans = "";
        string s = "";
        unordered_set<char> vis;
        vector<char> v(26,'#');
        for(char ch : baseStr){
            v[ch-'a'] = ch;
        }
        for(char ch : v){
            if(ch == '#') continue;
            s = "";
            dfs(ch,'#',s,mp,vis);
            sort(begin(s),end(s));
            v[ch-'a']=s[0];
            vis.clear();
        }
        for(char ch : baseStr){
            ans+=v[ch-'a'];
        }
        return ans;
    }
};