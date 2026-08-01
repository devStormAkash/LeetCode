#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<bool> mark(queries.size(),false);
        int n = queries[0].size();
        for(int i = 0; i<queries.size() ; i++){
            string s1 = queries[i];
            for(auto s2 : dictionary){
                int diff = 0;
                for(int i = 0; i<n ; i++){
                    if(s1[i]!=s2[i]) diff++;
                }
                if(diff<=2) mark[i]=1;
            }
        }
        vector<string> ans;
        for(int i = 0; i<queries.size() ; i++){
            if(mark[i]) ans.push_back(queries[i]);
        }
        return ans;
    }
};