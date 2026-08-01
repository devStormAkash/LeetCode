#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int mod = 1e9+7;
    vector<ll> fact,invfact;
    ll modPow(ll a, ll b){
        if(b==0) return 1;
        
        ll val = modPow(a,b/2)%mod;
        val = (val*val)%mod;
        if(b&1) val = (val*a)%mod;
        return val;
    }
    
    void init(int n){
        fact.assign(n+1,1);
        invfact.assign(n+1,1);
        for(int i=1;i<=n ; i++){
            fact[i]=fact[i-1]*i%mod;
        }
        invfact[n]=modPow(fact[n],mod-2);
        for(int i=n-1; i>=0 ; i--){
            invfact[i]=invfact[i+1]*(i+1)%mod;
        }
    }
    
    ll nCr(int n , int r){
       if(r<0 || r>n)  return 0;
        return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
    }
    int countValidSequences(int n, int k) {
        init(n);
        ll total = nCr(n-1,k-1);
        ll odd = 0;
        if((n-k)%2==0){
            int m = (n-k)/2;
            odd = nCr(m+k-1,k-1);
        }
        return (total-odd+mod)%mod;
    }
};

