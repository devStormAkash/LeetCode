#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        ll n = neededTime.size();
        vector<int> arr = neededTime;
        ll i = 0;
        ll j = 0;
        ll ans = 0;
        while(i<n&&j<n){
            char ch = colors[i];
            ll sum = 0;
            ll maxi = 0;
            while(j<n && ch == colors[j]){
                maxi = max(maxi,(ll)arr[j]);
                sum += arr[j];
                j++;
            }
            ans += sum-maxi;
            i=j;
        }
        return ans;
    }
};