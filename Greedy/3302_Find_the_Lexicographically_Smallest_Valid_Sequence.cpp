#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
    
        vector<int> righ_side_match_count(n1,0);
        int i,j;
        for(i = n1-1,j = n2-1 ; i>=0 && j>=0 ;){
            if(word1[i]==word2[j]){
                righ_side_match_count[i] = 1 + (i+1<n1?righ_side_match_count[i+1]:0);
                i--;
                j--;
            }else{
                righ_side_match_count[i] = (i+1<n1?righ_side_match_count[i+1]:0);
                i--;
            }
        }

        while(i>=0){
            righ_side_match_count[i] = righ_side_match_count[i+1];
            i--;
        }

        // for(int x : righ_side_match_count){
        //     cout << x << " ";
        // }

        vector<int> ans;
        int p1;
        int p2;

        for(int i = 0,j=0; i<n1&&j<n2 ;){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }
            else{ // we are trying to modify in this index
                if(i+1<n1 && n2-j-1 <= righ_side_match_count[i+1]){
                    ans.push_back(i);
                    p1 = i+1;
                    p2 = j+1;
                    break;
                }else{
                    i++;
                }
            }
        }

        // add remaining characters
        for(int i = p1,j=p2; i<n1&&j<n2 ;){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(ans.size() == n2){
            return ans;
        }
        return {};
    }
};