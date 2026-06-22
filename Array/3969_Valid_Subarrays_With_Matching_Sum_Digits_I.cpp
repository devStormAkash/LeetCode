#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll> pref_sum(n+1,0);
        for(int i = 0; i<n ; i++){
            pref_sum[i+1] = pref_sum[i]+(ll)nums[i];
        }
        for(ll x : pref_sum){
            cout << x << " ";
        }
        cout << endl;
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = i; j <= n ; j++){
                ll sum = pref_sum[j]-pref_sum[i-1];
                // string s = to_string(sum);
                // cout << s << " ";
                ll len = (ll)log10(sum);
                if(sum%10==sum/(ll)pow(10,len) && sum%10 == x) ans++;
            }
        }
        return ans;
    }
};