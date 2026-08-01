#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int sr = startPos[0];
        int er = homePos[0];
        int sc = startPos[1];
        int ec = homePos[1];

        int ans = 0;
        if(sr<=er){
            for(int i = sr+1; i<=er ; i++){
                ans+=rowCosts[i];
            }
        }else{
            for(int i = sr-1; i>=er ; i--){
                ans+=rowCosts[i];
            }
        }
        
        if(sc<=ec){
            for(int i = sc+1; i<=ec ; i++){
                ans+=colCosts[i];
            }
        }else{
            for(int i = sc-1; i>=ec ; i--){
                ans+=colCosts[i];
            }
        }
        
        return ans;
    }
};