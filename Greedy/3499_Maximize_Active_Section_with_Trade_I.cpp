#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    void print_arr(vector<ll>& arr){
        for(auto x : arr){
            cout << x << " ";
        }
        cout << endl;
    }

    int maxActiveSectionsAfterTrade(string s) {
        if(s.size()==1 && s[0]=='1') return 1;
        s = '1'+s+'1';
        ll n = s.size();
        
        vector<ll> split;
        ll ones = 0;
        split.push_back(1);
        for(ll i = 1; i<n; i++){
            if(s[i]==s[i-1]){
                split.back()+=1;
            }else{
                split.push_back(1);
            }
            if(i != n-1){
                if(s[i]=='1') ones++;
            }
        }

        // cout << ones << endl;

        // print_arr(split);

        ll ans = 0;
        ll size = split.size();
        if(size == 1) return split[0]-2;
        for(ll i = 2; i<size-1; i+=2){
            ll curr = split[i];
            ll next = ((i+1==size-1)?split[i+1]-1:split[i+1]);
            ll nextnext = ((i+2==size-1)?split[i+2]-1:split[i+2]);
            ll prev = ((i-1==0)?split[i-1]-1:split[i-1]);
            ll prevprev = ((i-2==0)?split[i-2]-1:split[i-2]);
            ll x = prevprev+prev+curr+next+nextnext+(ones-nextnext-prevprev-curr);
            ans = max(ans,x);
        }
        ans = max({ans,split[0]-1,split[size-1]-1,ones});
        return ans;
    }
};