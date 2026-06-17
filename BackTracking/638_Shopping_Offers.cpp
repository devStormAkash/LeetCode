#include <iostream>
#include <vector> 
#include<climits>
#include<unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<string,int> mp;
    bool isValidOffer(vector<int>& special,vector<int>& needs){
        for(int i = 0 ; i<needs.size() ; i++){
            if(needs[i]<special[i]) return false;
        }
        return true;
    }

    int helper(vector<int>& price,vector<vector<int>>& special,vector<int>& needs){
        int ans = INT_MAX;
        int n = needs.size();
        string s = "";
        for(int i = 0 ; i<n ;i++){
            s+=to_string(needs[i])+'#';
        }
        if(mp.count(s)) return mp[s];
        // price from special offer
        for(int i = 0 ; i<special.size() ; i++){
            if(isValidOffer(special[i],needs)){
                for(int j = 0 ; j<n ; j++){
                    needs[j]-=special[i][j];
                }
                ans = min(ans,special[i][n]+helper(price,special,needs));
                for(int j = 0 ; j<needs.size() ; j++){
                    needs[j]+=special[i][j];
                }
            }
        }

        // price without special offer
        int sum = 0;
        for(int i = 0;i<n ; i++){
            sum+=(price[i]*needs[i]);
        }

        return mp[s]=min(sum,ans);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price,special,needs);
    }
};