#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int fn(TreeNode* root,int& ans){
        if(root == NULL) return -1e9;
        if(root->left==NULL&&root->right==NULL){
            ans++;
            return root->val;
        }

        int left_val = fn(root->left,ans);
        int right_val = fn(root->right,ans);
        int maxi = max({root->val,left_val,right_val});
        if(root->val == maxi){
            ans++;
        }

        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        fn(root,ans);
        return ans;
    }
};