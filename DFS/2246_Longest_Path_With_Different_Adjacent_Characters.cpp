#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans = 0;

    int dfs(int node,int par,unordered_map<int,vector<int>>& mp,string& s){
        multiset<int> st;
        for(int child : mp[node]){
            if(child == par) continue;
            int path = dfs(child,node,mp,s);
            if(s[node]==s[child]) continue;
            st.insert(path);
        }
        int longest = 0;
        int second_longest = 0;
        if(st.size()>=2){
            auto it1 = st.rbegin();
            auto it2 = next(it1);
            longest = *it1;
            second_longest = *it2;
        }
        else if(st.size()==1){
            longest = *(st.rbegin());
        }

        int ek_achha_hai = max(second_longest,longest)+1;
        int root_achha_hai = 1;
        int niche_ans_mil_gya = second_longest + longest + 1; // we cannot return it because its shape does not satisfy path shape

        ans = max({ans,ek_achha_hai,root_achha_hai,niche_ans_mil_gya});

        return max(ek_achha_hai,root_achha_hai);

    }

    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>> mp;
        for(int i = 1 ; i<s.size() ; i++){
            int u = i;
            int v = parent[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(0,-1,mp,s);
        return ans;
    }
};