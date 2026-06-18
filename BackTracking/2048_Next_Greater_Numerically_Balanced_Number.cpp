#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    string global_s = "0";
    void helper(string& ans,int l , int n , set<int>& st){
        if(l<0) return;
        if(l==0){
            string p = ans;
            sort(begin(p),end(p));
            do{
                if(stoi(p)>n && (stoi(global_s)<n || stoi(p)<stoi(global_s)) ){
                    global_s = p;
                }
            }while(next_permutation(begin(p),end(p)));
            return;
        }

        for(int i = 1 ; i<= 9 ; i++){
            if(st.count(i)) continue;
            st.insert(i);
            ans+=string(i,i+'0');
            helper(ans,l-i,n,st);
            ans.erase(ans.size()-i);
            st.erase(i);
        }
        return;
    }

    int nextBeautifulNumber(int n) {
        if(n==0) return 1;
        string s = to_string(n);
        int sz = s.size();
        int l;
        if(s[0]-'0'<sz) l = sz;
        if(s[0]-'0'>sz) l = sz+1;
        if(s[0]-'0' == sz){
            string str = "";
            for(int i = 1; i<= sz ; i++){
                str += to_string(sz);
            }
            cout << str;
            int val = stoi(str);
            if(n>=val) l = sz+1;
            else l = sz;
        }
        set<int> st;
        string ans = "";
        helper(ans,l,n,st);
        int val = stoi(global_s);
        return val;
    }
};