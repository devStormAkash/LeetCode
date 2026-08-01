#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n,0);
        for(auto it : shifts){
            int st = it[0];
            int end = it[1];
            int dir = it[2];
            int val = (dir==0?-1:1);
            arr[st] += val;
            if(end+1<n) arr[end+1] += -val;
        }
        for(int i = 1; i<n ; i++){
            arr[i]+=arr[i-1];
            arr[i]%=26;
        }
        arr[0]%=26;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        // for(int x:arr){
        //     cout << x << " ";
        // }
        for(int i = 0; i<n ; i++){
            int idx = s[i]-'a';
            int new_idx = -1;
            if(arr[i]>0){
                new_idx = (idx+arr[i])%26;
            }else{
                new_idx = (idx+arr[i]+26)%26;
            }
            s[i] = alpha[new_idx];
        }
        return s;
    }
};