#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fn(string s){
        if(s.empty()) return "";

        int n = s.size();
        vector<string> arr;
        int i = 0;
        int ptr = 0;
        int sum = 0;
        while(i<n){
            if(s[i]=='1') sum+=1;
            else sum-=1;
            if(sum==0){
                if(i==n-1 && arr.size()==0){
                    string str = "";
                    if(s.size()>2) str = s.substr(1,n-2);
                    str = fn(str);
                    str = "1"+str+"0";
                    arr.push_back(str);
                    break;
                }
                string str = s.substr(ptr,i-ptr+1);
                str = fn(str);
                arr.push_back(str);
                i++;
                ptr = i;
            }else i++;
        }
        
        sort(begin(arr),end(arr),[](const string & a,const string &b){
            return a>b;
        });
        string ans = "";
        for(auto sub : arr){
            ans+=sub;
        }
        return ans;
    }
    string makeLargestSpecial(string s) {
        return fn(s);
    }
};