#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(char ch : s){
            mp[ch]+=1;
        }
        string ss = "";
        char mid='#';
        for(auto it : mp){
            char ch = it.first;
            int n = it.second;
            if(n%2==1){
                mid = ch;
            }
            string str = string(n/2,ch);
            ss+=str;
        }
        string temp = ss;
        reverse(begin(temp),end(temp));
        if(mid=='#') return ss+temp;
        return ss+mid+temp;
    }
};