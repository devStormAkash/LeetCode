#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(string moves) {
        int u = 0, d = 0, l = 0, r = 0, space  = 0;
        for(char ch : moves){
            if(ch == 'U') u++;
            else if(ch == 'D') d++;
            else if(ch == 'L') l++;
            else if(ch == 'R') r++;
            else space++;
        }
        return abs(l-r)+abs(u-d)+space;
    }
};