#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int k = target;

        // Find the prefix sum rowwise
        for(int r = 0; r<n ; r++){
            for(int c = 1; c<m ; c++){
                matrix[r][c] += matrix[r][c-1];
            }
        }

        // now count sub arraus , for clarity see the subset sum equsl k, watch mik video
        int count = 0;
        for(int st_col = 0; st_col < m ; st_col++){
            for(int c = st_col; c<m ; c++){
                unordered_map<int,int> mp;
                mp[0]=1;
                int cum_sum = 0;
                for(int r = 0; r<n ; r++){
                    cum_sum += (st_col>=1?matrix[r][c]-matrix[r][st_col-1]:matrix[r][c]);
                    if(mp.count(cum_sum-k)){
                        count+=mp[cum_sum-k];
                    }
                    mp[cum_sum]+=1;
                }
            }
        }

        return count;
    }
};