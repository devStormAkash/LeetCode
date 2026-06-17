#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rev(vector<int>& v,int i , int j){
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int> grayCode(1<<n);
        for(int i = 0 ; i<1<<n ; i++){
            // G(i)=i⊕(i>>1)
            grayCode[i] = i^(i>>1);
        }
        int k;
        for(int i = 0 ; i<1<<n ; i++){
            if(grayCode[i] == start){
                k = i;
                break;
            }
        }
        int m = 1<<n;
        rev(grayCode,0,m-1);
        rev(grayCode,0,m-k-1);
        rev(grayCode,m-k,m-1);
        return grayCode;
    }
};