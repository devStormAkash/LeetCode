#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// using ll = long long;
// class Solution {
// public:
//     int brokenCalc(int startValue, int target) {
//         if(target<=startValue) return startValue-target;
//         int steps = 0;
//         ll st = startValue;
//         ll end = target;
//         queue<ll> q;
//         q.push(st);
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 ll x = q.front();
//                 q.pop();
//                 if(x==target) return steps;
//                 if(x-1>=target/2){
//                     q.push(x-1);
//                 }
//                 if(x<=target) q.push(x*2);
//             }
//             steps++;
//         }
//         return -1;
//     }
// };


using ll = long long;
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        ll steps = 0;
        if(target<=startValue) return startValue-target;
        ll st = startValue;
        while(st!=target){
            if(target%2==1){
                target++;
                steps++;
            }
            else{
                target/=2;
                steps++;
            }
            if(target<st){
                steps+=(st-target);
                break;
            }
        }
        return steps;
    }
};