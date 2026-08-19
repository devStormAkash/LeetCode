#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int prod(int n){
        int rs = 1;
        while(n>0){
            rs*=(n%10);
            n/=10;
        }
        // cout <<rs << endl;
        return rs;
    }
    int smallestNumber(int n, int t) {
        for(int i = n;i<=100 ; i++){
            if(prod(i)%t==0){
                return i;
            }
        }
        return -1;
    }
};