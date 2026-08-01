#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        string ans = "";
        int count = 0;
        while(s>=9){
            ans+=to_string(9);
            s-=9;
            count++;
        }
        if(s==0 && count<=n && ans.size()>0){
            for(int i = 1; i<=(n-count) ; i++){
                ans+=to_string(0);
            }
            return stoi(ans);
        }
        if(count<n){
            ans+=to_string(s);
            count++;
            for(int i = 1; i<=(n-count) ; i++){
                ans+=to_string(0);
            }
            return stoi(ans);
        }else{
            return -1;
        }
    }
};