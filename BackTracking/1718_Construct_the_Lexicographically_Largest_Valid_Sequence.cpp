#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    bool helper(int idx,int n,vector<int>& ds,set<int> used){
        if(idx == ds.size()){
            return true;
        }
        if(ds[idx]!=-1) return helper(idx+1,n,ds,used);

        for(int val = n ; val>=1 ; val--){
            if(val == 1){
                if(ds[idx]==-1 && !used.count(val)){
                    ds[idx]=val;
                    used.insert(val);
                    if(helper(idx+1,n,ds,used)) return true;
                    used.erase(val);
                    ds[idx]=-1;
                }
            }
            else{
                if(idx+val<ds.size() && ds[idx] == -1 && ds[idx+val] == -1 && !used.count(val)){
                    ds[idx]=val;
                    ds[idx+val]=val;
                    used.insert(val);
                    if(helper(idx+1,n,ds,used)) return true;
                    used.erase(val);
                    ds[idx]=-1;
                    ds[idx+val]=-1;
                }
            }
        }
        
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int> ds(2*n-1,-1);
        set<int> used;
        helper(0,n,ds,used);
        return ds;
    }
};