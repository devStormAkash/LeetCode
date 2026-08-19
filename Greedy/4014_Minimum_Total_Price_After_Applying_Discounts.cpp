#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int m = prices.size();
        int n = discounts.size();
        sort(begin(prices),end(prices));
        sort(begin(discounts),end(discounts));
        int limit = n;
        if(n>m) limit = m;

        double ans = 0.0;

        int i,j;
        for(i = m-1,j = n-1; i>=0 && j>=0 && limit>=0; limit--){
            int p = prices[i];
            int d = discounts[j];
            ans+= (double)(p*(100-d))/100;
            i--;
            j--;
        }

        while(i>=0){
            ans += prices[i];
            i--;
        }

        return ans;
    }
};