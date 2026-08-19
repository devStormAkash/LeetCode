#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> lcs(n1+1,vector<int>(n2+1,0));

        // Prepare the lcs table
        for(int i = 1 ; i<=n1 ; i++){
            for(int j = 1; j<=n2 ; j++){
                if(str1[i-1]==str2[j-1]){
                    lcs[i][j] = 1+lcs[i-1][j-1];
                }else{
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }

        // Build the string now
        string ans = "";
        int i = n1;
        int j = n2;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                char ch = str1[i-1];
                ans+=ch;
                i--;
                j--;
            }
            else if(i-1>=0 && j-1>=0 && lcs[i-1][j]>=lcs[i][j-1]){
                char ch = str1[i-1];
                ans+=ch;
                i--;
            }else{
                char ch = str2[j-1];
                ans+=ch;
                j--;
            }
        }

        while(i>0){
            ans+=str1[i-1];
            i--;
        }

        while(j>0){
            ans+=str2[j-1];
            j--;
        }

        // Reverese the ans
        reverse(begin(ans),end(ans));
        return ans;

    }
};