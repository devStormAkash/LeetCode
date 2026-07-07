#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        if(n1>n2) return false;
        if(n1 == 1 && n2 == 1) return 1;
        bool ans = false;
        int j = 0;
        int i = 0;
        int last_i = 0;
        while(j<n1 && i<n2){
            if(s[j]==t[i]){
                last_i = i;
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j>=n1) return true;
        j++;
        i = last_i+1;

        if(j>=n1 && i>=n2){
            int new_i = n2-1,new_j=n1-1;
            int new_last_i;
            while(new_j>=0 && new_i>=0){
                if(s[new_j]==t[new_i]){
                    new_last_i = new_i;
                    new_i--;
                    new_j--;
                }else{
                    new_i--;;
                }
            }
            return new_j==0 && new_last_i>0;
        }

        while(j<n1 && i<n2){
            if(s[j]==t[i]){
                i++;
                j++;
                last_i = i;
            }else{
                i++;
            }
        }
        if(j>=n1) return true;
        return false;
    }
};