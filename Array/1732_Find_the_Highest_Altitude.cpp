#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = INT_MIN;
        int sum = 0;
        ans = max(ans,sum);
        for(int x : gain){
            sum+=x;
            ans = max(ans,sum);
        }
        return ans;
    }
};