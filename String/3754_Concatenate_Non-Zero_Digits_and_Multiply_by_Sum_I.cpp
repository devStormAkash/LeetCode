#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        string s = "";
        for(char ch : str){
            if(ch!='0') s+=ch;
        }

        ll num = s.empty()?0:stol(s);
        if(num==0) return 0;
        ll sum = 0;
        for(char ch : s){
            sum+=(ch-'0');
        }
        return sum*num;
    }
};