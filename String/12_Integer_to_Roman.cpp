#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> four = {"IV","XL","CD"};
        vector<string> nine = {"IX","XC","CM"};
        vector<string> power10 = {"I","X","C","M"};
        vector<string> five = {"V","L","D"};

        int p = 3;
        string ans = "";
        for(int i = num ; i!=0 ;){
            if(p==3){
                int x = i / pow(10,p);
                for(int j = 0 ; j< x ; j++){
                    ans+=power10[p];
                }
            }else{
                int x = i / (int)pow(10,p);
                if(x == 4){
                    ans+=four[p];
                }
                else if(x == 9){
                    ans+=nine[p];
                }else{
                    if(x<=3){
                        for(int j = 0 ; j<x ; j++){
                            ans+=power10[p];
                        }
                    }else{
                        ans+=five[p];
                        for(int j = 0 ; j<x-5; j++){
                            ans+=power10[p];
                        }
                    }
                }
            }
            i = i%(int)pow(10,p);
            p--;
        }

        return ans;

    }
};


// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<int>val={1000,900,500,400,100,90,50,40,10,9,5,4,1};
//         vector<string>sym={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//         string ans="";
//         for(int i=0;i<val.size();i++){
//             while(num>=val[i]){
//                 ans+=sym[i];
//                 num-=val[i];
//             }
//         }
//         return ans;
//     }
// };