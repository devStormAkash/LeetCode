#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        int secondmaxi = 0;
        while(n>0){
            int x = n%10;
            if(x>maxi){
                secondmaxi = maxi;
                maxi = max(maxi,x);
            }else{
                secondmaxi = max(secondmaxi,x);
            }
            n/=10;
        }
        return maxi*secondmaxi;
    }
};