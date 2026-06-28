#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// typedef tuple<int,int,int> tiii;
// class Solution {
// public:
//     int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
//         unordered_map<int,vector<pair<int,int>>> adj;
//         for(auto it : edges){
//             int u = it[0];
//             int v = it[1];
//             int wt = it[2];
//             adj[u].push_back({v,wt});
//         }
//         vector<int> dist(n,INT_MAX);
//         priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
//         pq.push({0,0,1}); // {distace,node,consecutive identical charcter count}
//         dist[0]=0;
//         while(!pq.empty()){
//             auto [dis,node,count] = pq.top();
//             pq.pop();
//             if(dis>dist[node]) continue;
//             for(auto it : adj[node]){
//                 int adjNode = it.first;
//                 int wt = it.second;
//                 int new_count = (labels[adjNode]==labels[node])? count+1 : 1;
//                 if(new_count>k) continue;
//                 if(wt+dist[node]<dist[adjNode]){
//                     dist[adjNode] = wt+dist[node];
//                     pq.push({dist[adjNode],adjNode,new_count});
//                 }
//             }
//         }
//         return dist[n-1] == INT_MAX ? -1 : dist[n-1];
//     }
// };


typedef tuple<int,int,int> tiii;
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        // vector<int> dist(n,INT_MAX);
        vector<vector<int>> dist(n,vector<int>(k+1,INT_MAX)); // Dijkstra on states (node, count), where count is the current consecutive run length of labels[node]
        priority_queue<tiii,vector<tiii>,greater<tiii>> pq;
        pq.push({0,0,1}); // {distace,node,consecutive identical charcter count}
        // dist[0]=0;
        dist[0][1] = 0;
        while(!pq.empty()){
            auto [dis,node,count] = pq.top();
            pq.pop();

            if(dis>dist[node][count]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                int new_count = (labels[adjNode]==labels[node])? count+1 : 1;
                if(new_count>k) continue;
                if(wt+dist[node][count]<dist[adjNode][new_count]){
                    dist[adjNode][new_count] = wt+dist[node][count];
                    pq.push({dist[adjNode][new_count],adjNode,new_count});
                }
            }
        }

        // The answer is the minimum distance among all states ending at node n - 1.
        int ans = INT_MAX;
        for(int i = 1; i<=k; i++){
            ans = min(ans,dist[n-1][i]);
        }

        return ans == INT_MAX ? -1 : ans;
        
    }
};
