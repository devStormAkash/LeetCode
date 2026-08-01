#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    ll K;
    ll ncr(ll n, ll r){
        r = min(r,n-r);
        ll res = 1;
        for(int i = 1; i<=r ; i++){
            res = res*(n-r+i)/i;
            if(res>K) break;
        }
        return res;
    }

    string smallestPalindrome(string s, int k) {
        K=k;
        vector<ll> v(26,0); // frequency array
        ll n = s.size();
        for(ll i = 0; i<n/2; i++){
            v[s[i]-'a']+=1;
        }
        string mid = "";
        if(n%2==1) mid += s[n/2];

        ll sz = accumulate(begin(v),end(v),0);
        // calculate number of ways
        ll ws = 1;
        for(ll l = 0; l<26 ; l++){
            if(v[l]==0) continue;
            ws*=ncr(sz,v[l]);
            if(ws>1e6) break;
            sz-=v[l];
        }
        if(k>ws) return "";
        
        // Build the left string
        string left = "";
        for(int i = 0; i<n/2 ; i++){
            for(int j = 0; j<26 ; j++){
                if(v[j]==0) continue;
                v[j]--;
                ll size = accumulate(begin(v),end(v),0);
                // calculate number of ways
                ll ways = 1;
                for(ll l = 0; l<26 ; l++){
                    if(v[l]==0) continue;
                    ll x = ncr(size,v[l]);
                    if(x>1e6){
                        ways = 1e6;
                        break;
                    }
                    ways*=x;
                    if(ways>k) break;
                    size-=v[l];
                }
                v[j]++;
                // Now based on number of ways take decision to keep the current character or not
                if(k<=ways){
                    left+=(j+'a');
                    v[j]--;
                    break;
                }else{
                    k-=ways;
                }
            }
        }

        // Build the palindrome
        string right = left;
        reverse(begin(right),end(right));
        string ans = left + mid + right;
        return ans;
    }
};