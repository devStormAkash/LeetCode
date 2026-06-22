#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int max_h(int id_r,int id_l,int lh , int rh){
        int x = (id_r-id_l)+(lh+rh);
        return x/2;
    }
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        int m = restrictions.size();
        if(m==0) return n-1;
        restrictions.push_back({1,0});
        m++;
        sort(begin(restrictions),end(restrictions));

        // left to right limit pass
        for(int i = 1; i<m ; i++){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i-1][1]+(restrictions[i][0]-restrictions[i-1][0]));
        }

        // right to left limit pass
        for(int i = m-2; i>=0 ; i--){
            restrictions[i][1] = min(restrictions[i][1],restrictions[i+1][1]+(restrictions[i+1][0]-restrictions[i][0]));
        }

        int ans = INT_MIN;
        int first_h = max_h(restrictions[0][0],1,0,restrictions[0][1]);
        ans = max(ans,first_h);
        for(int i = 0 ; i<restrictions.size()-1 ; i++){
            int id_r = restrictions[i+1][0];
            int id_l = restrictions[i][0];
            int rh = restrictions[i+1][1];
            int lh = restrictions[i][1];
            ans = max(ans,max_h(id_r,id_l,lh,rh));
        }
        ans = max(ans,restrictions[m-1][1]+(n-restrictions[m-1][0]));
        return ans;

    }
};