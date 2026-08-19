#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int count = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i<capacity.size() ; i++){
            if(capacity[i]-rocks[i]==0){
                count++;
                continue;
            }
            pq.push(capacity[i]-rocks[i]);
        }

        int n = additionalRocks;
        while(n>0&&!pq.empty()){
            int val = pq.top();
            pq.pop();
            n-=val;
            if(n>=0) count++;
        }
        return count;
    }
};