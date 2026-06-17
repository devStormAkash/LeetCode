#include <iostream>
#include <vector> 
#include<climits>

using namespace std;
using ll = long long;
class Solution {
public:
    vector<char> operators = {'+', '-', '*'};
    void helper(int idx, string& num, string& ds, vector<string>& ans,
                int& target, ll  curr_val,ll prev_val,char prev_operator) {
        if (idx == num.size()) {
            if (curr_val == target)
                ans.push_back(ds);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            string s = num.substr(idx, i - idx + 1);
            if (s[0] == '0' && s.size() > 1)
                break;
            ll val = stoll(s);    
            if (ds.size() < 1) {
                ds += s;
                helper(i + 1, num, ds, ans,target , val,val,'#');
                ds.erase(ds.size() - s.size());
            } else {
                for (char ch : operators) {
                    if(ch=='+'){
                        //curr_val+=val;
                        ds+='+'+s;
                        helper(i + 1, num, ds, ans,target , curr_val+val,val,ch);
                        ds.erase(ds.size() - s.size()-1);
                        //curr_val-=val;
                    }
                    else if(ch=='-'){
                        //curr_val-=val;
                        ds+='-'+s;
                        helper(i + 1, num, ds, ans,target , curr_val-val,val,ch);
                        ds.erase(ds.size() - s.size()-1);
                        //curr_val+=val;
                    }
                    else if(ch=='*'){
                        ll temp = curr_val;
                        ll next_prev_val = 0;
                        if(prev_operator!='#'){
                            if(prev_operator == '+'){
                                curr_val = curr_val-prev_val+(prev_val*val);
                            }
                            else if(prev_operator=='-'){
                                curr_val = curr_val+prev_val-(prev_val*val);
                            }
                            next_prev_val = prev_val*val;
                        }else{
                            next_prev_val = val;
                            curr_val *= val;
                        }
                        ds+='*'+s;
                        helper(i + 1, num, ds, ans,target , curr_val , next_prev_val, prev_operator);
                        ds.erase(ds.size() - s.size()-1);
                        curr_val = temp;
                    }
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) { 
        string ds = "";
        vector<string> ans;
        int curr_val = 0;
        helper(0,num,ds,ans,target,0,INT_MIN,'#');
        return ans;
    }
};