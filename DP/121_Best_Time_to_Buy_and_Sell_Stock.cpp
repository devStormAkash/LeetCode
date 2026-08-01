#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ll mini = LONG_MAX;
        ll ans = LONG_MIN;
        for(ll i = 0; i<prices.size() ; i++){
            mini = min<ll>(mini,prices[i]);
            ans = max<ll>(ans,prices[i]-mini);
        }
        return ans;
    }
};