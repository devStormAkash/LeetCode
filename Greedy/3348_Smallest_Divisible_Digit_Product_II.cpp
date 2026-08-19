#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
// class Solution {
// public:

//     bool fn(ll idx,string & s, vector<ll>& freq){
//         if(freq[0]==0&&freq[1]==0&&freq[2]==0&&freq[3]==0) return true;
//         if(idx==s.size()){
//             return false;
//         }

//         ll st = (s[idx]=='#')?1:s[idx]-'0';

//         char og = s[idx];
//         vector<ll> temp = freq;
//         for(ll i = st ; i<=9 ; i++){
//             char ch = i+'0';
//             if(i == 2 && freq[0]>0){
//                 freq[0]--;
//             }else if(i == 4 && freq[0]>0){
//                 if(freq[0]>=2){
//                     freq[0]-=2;
//                 }
//             }else if(i == 8 && freq[0]>0){
//                 if(freq[0]>=3){
//                     freq[0]-=3;
//                 }
//             }else if(i==3 && freq[1]>0){
//                 freq[1]--;
//             }else if(i==9 && freq[1]>0){
//                 if(freq[1]>=2){
//                     freq[1]-=2;
//                 }
//             }else if(i==5&&freq[2]>0){
//                 freq[2]--;
//             }else if(i==7&&freq[3]>0){
//                 freq[3]--;
//             }

//             s[idx]=ch;
//             if(fn(idx+1,s,freq)) return 1;
//             s[idx]=og;

//             freq[0] = temp[0];
//             freq[1] = temp[1];
//             freq[2] = temp[2];
//             freq[3] = temp[3];
//         }

//         return false;
//     }

//     string smallestNumber(string num, long long t) {
//         map<ll,int> mp;
//         ll n = t;
//         for(ll i = 2 ; i*i <= t ; i++){
//             while(t%i==0){
//                 mp[i]++;
//                 t/=i;
//             }
//         }
//         if(t>1){
//             mp[t]+=1;
//         }

//         for(auto [prime,cnt] : mp){
//             cout << prime << " --> " << cnt << endl;
//             if(prime>7){
//                 return "-1";
//             }
//         }

//         vector<ll> freq(4,0);
//         ll size = 0;
//         for(auto [prime,cnt] : mp){
//             size+=cnt;
//             if(prime == 2){
//                 freq[0]=cnt;
//             }else if(prime == 3){
//                 freq[1]=cnt;
//             }else if(5 == prime){
//                 freq[2] = cnt;
//             }else{
//                 freq[3] = cnt;
//             }
//         }

//         string s = num;
//         ll sz = num.size();
//         vector<ll> temp = freq;
//         while(!fn(0,s,freq)){
//             sz++;
//             s = string(sz,'#');
//             freq=temp;
//         }
//         if(s.size() == num.size()) return s;

//         ll idx = s.find('#');
//         string ans = s.substr(0,idx);

//         return ans;
//     }
// };


using ll = long long;
class Solution {
public:

    string remaining_length_string(ll val,ll n){
        string s = "";
        for(ll i = 9 ; i>=2 ; i--){
            while(val%i==0){
                s+=to_string(i);
                val/=i;
            }
        }

        ll dif = n - s.size();
        if(dif>0){
            for(ll i = 1; i<=dif ; i++){
                s+=to_string(1);
            }
        }
        reverse(begin(s),end(s));
        return s;
    }

    string smallestNumber(string num, long long t) {
        map<ll,int> mp;
        // ll n = t;
        ll p = t;
        ll n = num.size();
        for(ll i = 2 ; i*i <= t ; i++){
            while(t%i==0){
                mp[i]++;
                t/=i;
            }
        }
        if(t>1){
            mp[t]+=1;
        }

        for(auto [prime,cnt] : mp){
            // cout << prime << " --> " << cnt << endl;
            if(prime>7){
                return "-1";
            }
        }

        vector<ll> remaining_factor(n+1,p); // here the ith index represents if we use 0 to i-1 digits in s then what is remaing t value for i to n-1 digits in s

        for(ll i = 0; i<n ; i++){
            ll d = num[i]-'0';
            if(d==0) break;
            remaining_factor[i+1] = remaining_factor[i]/gcd(remaining_factor[i],d);
        }

        if(remaining_factor[n]==1) return num;

        ll st_idx = num.find('0');
        if(st_idx==-1){
            st_idx = n-1;
        }

        for(ll i = st_idx ; i>=0 ; i--){
            ll required = remaining_factor[i];
            ll freeslots = n-1-i;
            for(ll digit = num[i]-'0'+1 ; digit<=9 ; digit++){
                ll further_required = required/gcd(required,digit);
                string required_number = remaining_length_string(further_required,freeslots);
                if(required_number.size()==freeslots){
                    return num.substr(0,i) + char(digit+'0') + required_number;
                }
            }
        }

        return remaining_length_string(p,n+1);
    }
};