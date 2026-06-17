#include <iostream>
#include <vector> 
#include<climits>
#include<unordered_map>
using namespace std;
using ll = long long;
class Solution {
public:
    bool helper(int idx , string& num,vector<int>& ds){
        if(idx == num.size()){
            return ds.size()>=3;
        }

        for(int i = idx ; i<num.size() ; i++){
            string s = num.substr(idx,i-idx+1);
            if(s[0]=='0' && s.size()>1) break;
            ll val = stoll(s);
            if(val>INT_MAX) break;
            int n = ds.size();
            if(n<2 || val==(ll)ds[n-1]+(ll)ds[n-2]){
                if(val<=INT_MAX){
                    ds.push_back((int)val);
                    if(helper(i+1,num,ds)) return true;
                    ds.pop_back();
                }
            }
        }

        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ds;
        if(helper(0,num,ds)) return ds;
        else return {};
    }
};