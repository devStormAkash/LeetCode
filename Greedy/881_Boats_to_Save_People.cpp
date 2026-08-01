#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int n = people.size();
        sort(begin(people),end(people));
        int actual_limit = limit;
        int i = 0;
        int j = n-1;
        int boats = 0;

        while(i<=j){
            if(people[i]+people[j]<=limit){
                boats++;
                i++;
                j--;
            }else{
                boats++;
                j--;
            }
        }
        
        return boats;
    }
};