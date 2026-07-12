#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1e9+7;
ll mul(ll a, ll b){return ((a%mod)*(b%mod))%mod;}
ll add(ll a, ll b){return ((a%mod)+(b%mod))%mod;}
ll sub(ll a, ll b){return ((a%mod)-(b%mod)+mod)%mod;}

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ll n = s.size();
        // Prefix Sum
        vector<ll> pref_sum(n);
        for(ll i = 0; i<n ; i++){
            pref_sum[i] = s[i]-'0';
        }

        for(ll i = 1;i<n; i++){
            pref_sum[i]+=pref_sum[i-1];
        }

        // 10th Power array
        vector<ll> power_of_10(n+1,1);
        for(ll i = 1; i<= n ; i++){
            power_of_10[i] = mul(power_of_10[i-1], 10);
        }

        // Prefix Integer Array
        vector<ll> pref_integer(n,0);
        for(ll i = 0; i<n ; i++){
            if(i == 0){
                pref_integer[0] = s[i]-'0';
            }else{
                if(s[i]-'0' == 0){
                    pref_integer[i]=pref_integer[i-1];
                }else{
                    pref_integer[i] = add(mul(pref_integer[i-1],10),s[i]-'0');
                }
            }
        }

        // Non zero digits count
        vector<ll> nz_digit_count(n);
        for(ll i = 0; i<n; i++){
            if(s[i]-'0'!=0) nz_digit_count[i] = 1;
        }

        for(ll i = 1; i<n; i++){
            nz_digit_count[i] += nz_digit_count[i-1];
        }

        // Now it is time to handle the queries
        ll m = queries.size();
        vector<int> result(m);
        for(ll i = 0; i<m ; i++){
            ll l = queries[i][0];
            ll r = queries[i][1];
            
            ll shift = nz_digit_count[r] - ((l-1>=0)?nz_digit_count[l-1]:0);
            ll val_r = pref_integer[r];
            ll val_l = (l-1>=0)?mul(pref_integer[l-1],power_of_10[shift]):0;

            ll x = sub(val_r,val_l);
            ll sum = (pref_sum[r])-((l-1>=0)?pref_sum[l-1]:0);
            ll ans = mul(x,sum);
            result[i]=ans;
        }

        return result;
    }
};