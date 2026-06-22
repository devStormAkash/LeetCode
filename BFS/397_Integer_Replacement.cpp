#include <iostream>
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<ll,ll>> q;
        q.push({n,0});
        set<long long> vis;
        vis.insert(n);
        while(!q.empty()){
            auto [node,steps] = q.front();
            q.pop();
            if(node == 1) return steps;
            if(node%2==0){
                if(!vis.count(node/2)){
                    vis.insert(node/2);
                    q.push({node/2,steps+1});
                }
            }else{
                if(!vis.count((ll)node+1)){
                    vis.insert((ll)node+1);
                    q.push({(ll)node+1,steps+1});
                }
                if(!vis.count(node-1)){
                    vis.insert(node-1);
                    q.push({node-1,steps+1});
                }
            }
        }
        return -1;
    }
};