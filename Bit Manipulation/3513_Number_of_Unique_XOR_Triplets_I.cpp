#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int binary_length = 0;
        int maxi = *max_element(begin(nums),end(nums));
        if(maxi<3) return maxi;
        while(maxi>0){
            maxi = maxi>>1;
            binary_length++;
        }
        return pow(2,binary_length);
    }
};