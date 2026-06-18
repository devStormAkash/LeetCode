#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
using ll = long long;
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2==1) return {};
        vector<ll> ans;
        ll i = 2;
        while(finalSum!=0){
            ll temp = finalSum;
            temp -= i;
            if(temp>=0){
                ans.push_back(i);
            }else{
                ll x = ans[ans.size()-1];
                ans.pop_back();
                ans.push_back(x+finalSum);
                return ans;
            }
            finalSum = temp;
            i+=2;
        }
        return ans;
    }
};