#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(string s) {
        int n = s.size();
        unordered_map<int,int> pallen;
        for(int mask = 0 ; mask<(1<<n) ; mask++){
            string sub = "";
            for(int i = 0 ; i<n ; i++){
                if(mask&(1<<i)){
                    sub+=s[i];
                }
            }
            string rev = sub;
            reverse(rev.begin(),rev.end());
            if(rev==sub){
                pallen[mask]=rev.size();
            }
        }
        vector<int> mask;
        for(auto it : pallen){
            mask.push_back(it.first);
        }
        int ans = 0;
        int m = mask.size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<m ;j++){
                if((mask[i]&mask[j])==0){
                    ans = max(ans,pallen[mask[i]]*pallen[mask[j]]);
                }
            }
        }
        return ans;
    }
};