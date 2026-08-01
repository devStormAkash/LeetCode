#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll n = prices.size();
        ll ans = LONG_MIN;
        ll score = 0;
        for(ll i = 0 ; i<n ; i++){
            score+=strategy[i]*prices[i];
        }
        ll normal_window = 0;
        ll modified_window = 0;
        for(ll i = 0; i<k ; i++){
            normal_window+=strategy[i]*prices[i];
            if(i>=k/2) modified_window+=prices[i];
        }
        ans = max(ans,score);
        ans = max(ans,score-normal_window+modified_window);

        ll i = 0;
        ll j = k-1;
        while(j<n){
            j++;
            if(j==n) break;
            modified_window+=prices[j];
            ll idx = j-k/2;
            modified_window-=prices[idx];

            normal_window+=prices[j]*strategy[j];
            normal_window+=prices[i]*(-1)*strategy[i];
            i++;
            ans = max(ans,score-normal_window+modified_window);
        }
        return ans;
    }
};