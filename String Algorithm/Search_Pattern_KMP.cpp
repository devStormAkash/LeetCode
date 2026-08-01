#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> LPS(string &pat){
        int len = 0;
        int n = pat.size();
        vector<int> lps(n);
        lps[0]=0;
        int i = 1;
        while(i<n){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> ans;
        vector<int> lps = LPS(pat);
        int i = 0;
        int j = 0;
        while(i<n){
            if(pat[j]==txt[i]){
                i++;
                j++;
            }
            if(j==m){
                ans.push_back(i-m);
                j = lps[j-1];
            }else if(pat[j]!=txt[i]){
                if(j!=0){
                    j = lps[j-1];
                }else{
                    i++;
                }
            }
        }
        
        return ans;
        
    }
};