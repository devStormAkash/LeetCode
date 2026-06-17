#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    void helper(vector<int>& arr,vector<int>& ds,vector<bool>& vis,string& ans){
        if(ds.size()==arr.size()){
            int hour = ds[0]*10+ds[1];
            int minute = ds[2]*10+ds[3];
            if(hour>23 || minute>59){
                return;
            }
            int prev_hour = (ans[0]-'0')*10+(ans[1]-'0');
            int prev_minute = (ans[3]-'0')*10+(ans[4]-'0');
            if(hour>=prev_hour){
                if((hour == prev_hour && minute>prev_minute) || hour>prev_hour){
                    ans = to_string(ds[0])+to_string(ds[1])+':'+to_string(ds[2])+to_string(ds[3]);
                }
            }
            return;
        }

        for(int i = 0 ; i<arr.size() ; i++){
            if(vis[i]) continue;
            if(i>0 && arr[i]==arr[i-1] && !vis[i-1]) continue;
            vis[i]=1;
            ds.push_back(arr[i]);
            helper(arr,ds,vis,ans);
            ds.pop_back();
            vis[i]=0;
        }
    }

    string largestTimeFromDigits(vector<int>& arr) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        string ans="";
        vector<bool> vis(n,false);
        vector<int> ds;
        helper(arr,ds,vis,ans);
        return ans;
    }
};