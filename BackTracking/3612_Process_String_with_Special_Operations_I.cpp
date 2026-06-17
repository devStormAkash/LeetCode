#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char ch : s){
            if(ch>=97 && ch<=122){
                ans+=ch;
            }else if(ch == '*' && ans.size()>=1){
                ans.pop_back();
            }else if(ch == '#'){
                ans+=ans;
            }else{
                reverse(begin(ans),end(ans));
            }
        }
        return ans;
    }
};