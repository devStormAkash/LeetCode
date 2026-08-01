#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        for(int i = 0; i<growTime.size() ; i++){
            arr.push_back({growTime[i],plantTime[i]});
        }
        sort(begin(arr),end(arr),[](const pair<int,int> &a , const pair<int,int> &b){
            if(a.first==b.first) return a.second>b.second;
            return a.first>b.first;
        });
        // for(auto x : arr){
        //     cout << x.first << " " << x.second << endl;
        // }
        int ans = 0;
        int cumulative = 0;
        for(int i = 0; i<arr.size() ; i++){
            cumulative += arr[i].second;
            ans = max(ans,cumulative+arr[i].first);
        }
        return ans;
    }
};