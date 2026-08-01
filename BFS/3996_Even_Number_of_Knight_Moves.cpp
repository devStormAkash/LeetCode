#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool canReach(vector<int>& start, vector<int>& target) {
        int d1[4]={1,1,-1,-1};
        int d2[4]={-1,1,-1,1};
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int steps = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                if(p.first == target[0]&&p.second == target[1]){
                    return steps%2==0;
                }

                // col
                for(int i = 0; i<4;i++){
                    int nr = r+1*d2[i];
                    int nc = c+2*d1[i];
                    if(nr>=0&&nr<=7&&nc>=0&&nc<=7){
                        q.push({nr,nc});
                    }
                }

                // row
                for(int i = 0; i<4;i++){
                    int nr = r+2*d1[i];
                    int nc = c+1*d2[i];
                    if(nr>=0&&nr<=7&&nc>=0&&nc<=7){
                        q.push({nr,nc});
                    }
                }
                
            }
            steps++;
        }

        return false;
    }
};