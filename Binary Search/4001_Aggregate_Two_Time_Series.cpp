#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int next_idx(int val,vector<vector<int>>& series){
        int l = 0;
        int r = series.size()-1;
        int ans = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(series[mid][0]>val){
                ans = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        for(auto it : series1){
            int u = it[0];
            int v = it[1];
            mp1[u]=v;
        }
        for(auto it : series2){
            int u = it[0];
            int v = it[1];
            mp2[u]=v;
        }
        
        for(int i = 0;i<series1.size();i++){
            int time = series1[i][0];
            int val = series1[i][1];
            if(mp2.count(time)){
                val+=mp2[time];
            }
            else{
                int idx = next_idx(time,series2);
                if(idx!=-1){
                    val+=series2[idx][1];
                }
            }
            ans.push_back({time,val});
        }

        for(int i = 0;i<series2.size();i++){
            int time = series2[i][0];
            int val = series2[i][1];
            if(mp1.count(time)) continue;
            int idx = next_idx(time,series1);
            if(idx!=-1){
                val+=series1[idx][1];
            }
            ans.push_back({time,val});
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};