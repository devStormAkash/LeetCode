#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n==1) return "";
        if(count(begin(palindrome),end(palindrome),'a')==n){
            palindrome[n-1]='b';
            return palindrome;
        }

        for(int i = 0; i<=n/2 ; i++){
            if(i==n/2){
                palindrome[n-1]='b';
            }
            else if(palindrome[i]!='a'){
                palindrome[i]='a';
                break;
            }
        }

        return palindrome;
    }
};