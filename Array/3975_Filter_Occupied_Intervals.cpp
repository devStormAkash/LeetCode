#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>> merged;
        int prev = INT_MAX;
        for(auto x : occupiedIntervals){
            int st = x[0];
            int end = x[1];
            if(merged.empty()){
                merged.push_back(x);
            }else{
                if(st-merged.back()[1]<=1){
                    merged.back()[1] = max(merged.back()[1],end);
                }else{
                    merged.push_back(x);
                }
            }
        }

        // for(auto x : merged){
        //     cout << x[0] << x[1] << endl;
        // }

        vector<vector<int>> ans;
        for(auto x : merged){
            int st = x[0];
            int end = x[1];

            if(end<freeStart){
                ans.push_back(x);
            }

            else if(st>freeEnd){
                ans.push_back(x);
            }

            else{
                if(freeStart>=1+st){
                    ans.push_back({st,freeStart-1});
                }
                
                if(freeEnd<=end-1){
                    ans.push_back({freeEnd+1,end});
                }
            }

            
        }

        return ans;
    }
};