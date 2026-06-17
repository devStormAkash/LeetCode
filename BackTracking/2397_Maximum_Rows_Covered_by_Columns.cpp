#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row_values;
        for(int i = 0 ; i<m ; i++){
            string s = "";
            for(int j = 0 ; j<n ; j++){
                s+=to_string(matrix[i][j]);
            }
            int val = stoi(s,nullptr,2);
            row_values.push_back(val);
        }

        int ans = 0;
        for(int mask = 0 ; mask<(1<<n) ; mask++){
            int num_of_ones = __builtin_popcount(mask);
            if(num_of_ones==numSelect){
                int count = 0;
                for(int i = 0 ; i<row_values.size() ; i++){
                    if((mask|row_values[i])==mask) count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};