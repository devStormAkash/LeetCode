#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {
//         set<pair<ll,ll>> st;
//         for(auto x : intervals){
//             st.insert({x[0],x[1]});
//         }

//         ll n = intervals.size();
//         for(ll i = 0;i<n ; i++){
//             ll c = intervals[i][0];
//             ll d = intervals[i][1];
//             for(ll j = 0; j<n;j++){
//                 if(i==j) continue;
//                 ll a = intervals[j][0];
//                 ll b = intervals[j][1];
//                 if(c<=a&&b<=d){
//                     if(st.count({a,b})) st.erase({a,b});
//                 }
//             }
//         }
//         return st.size();
//     }
// };

using ll = long long;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        ll ans = 1;
        ll n = intervals.size();
        sort(intervals.begin(),intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) 
            return a[1] > b[1]; // descending order for second element
            return a[0] < b[0];     // ascending order for first element
        });

        ll last_used = 0;
        for(ll i = 1; i<n ; i++){
            if(intervals[i][1]>intervals[last_used][1] && intervals[i][0]>intervals[last_used][0]){
                ans++;
                last_used = i;
            }
        }
        return ans;
    }
};