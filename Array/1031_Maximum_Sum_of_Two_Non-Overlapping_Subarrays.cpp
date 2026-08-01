#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        for(int i = 0; i<n ; i++){
            pref[i] = suff[i] = nums[i];
        }
        for(int i = 1; i<n ; i++){
            pref[i]+=pref[i-1];
        }
        for(int i = n-2; i>=0 ; i--){
            suff[i]+=suff[i+1];
        }

        int n1 = firstLen;
        int n2 = secondLen;

        int ans = 0;

        // First n1 size then n2 size
        for(int i = n1-1; i<n-n2; i++){
            int left = pref[i]-(i-n1>=0?pref[i-n1]:0);
            for(int j = i+1;j<=n-n2; j++){
                int right = suff[j]-(j+n2<n?suff[j+n2]:0);
                ans = max(ans,left+right);
            }
        }

        // First n2 size then n1 size
        for(int i = n2-1; i<n-n1; i++){
            int left = pref[i]-(i-n2>=0?pref[i-n2]:0);
            for(int j = i+1;j<=n-n1; j++){
                int right = suff[j]-(j+n1<n?suff[j+n1]:0);
                ans = max(ans,left+right);
            }
        }

        return ans;
    }
};