#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        set<int> s;
        for(int i = 0 ; i<haystack.size() ; i++){
            if(haystack[i] == needle[0] && i+(int)needle.size() <= haystack.size()){
                s.insert(i);
            }
        }

        unordered_map<string,int> mp;

        for(auto i : s){
            string str = "";
            for(int j = i ; j<i+needle.size() ; j++){
                str.push_back(haystack[j]);
            }
            if(str==needle){
                return i;
            }
        }

        return -1;
    }
};