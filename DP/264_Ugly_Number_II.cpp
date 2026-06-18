#include <iostream>
#include<bits/stdc++.h>
using namespace std; 
using ll = long long;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(1);
        set<int> st;
        set<int> isused;
        isused.insert(1);
        while(st.size() != n){
            int x = pq.top();
            st.insert(x);
            pq.pop();
            if((ll)x*2 <= INT_MAX && !isused.count(x*2)){
                pq.push(x*2);
                isused.insert(x*2);
            }
            if((ll)x*3 <= INT_MAX && !isused.count(x*3)){
                pq.push(x*3);
                isused.insert(x*3);
            }
            if((ll)x*5 <= INT_MAX && !isused.count(x*5)){
                pq.push(x*5);
                isused.insert(x*5);
            }
        }
        for(auto x: st){
            cout<<x<<endl;
        }
        return *st.rbegin();
    }

};

// 3 pointer approach
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n+1); // v[i] represents 'i'th ugly number
        int i2,i3,i5;
        i2=i3=i5=1; // first all points to first ugly number
        v[1]=1; // 1 is first ugly number
        for(int i = 2 ; i<=n ; i++){
            int i2ugly = v[i2]*2;
            int i3ugly = v[i3]*3;
            int i5ugly = v[i5]*5;
            int minUgly = min({i2ugly,i3ugly,i5ugly});
            if(minUgly == i2ugly){
                i2++;
            }
            if(minUgly == i3ugly){
                i3++;
            }
            if(minUgly == i5ugly){
                i5++;
            }
            v[i]=minUgly;
        }
        return v[n];
    }

};