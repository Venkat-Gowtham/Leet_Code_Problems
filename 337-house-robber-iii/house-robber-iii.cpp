/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<TreeNode*,int>,int>mp;
    int findMax(TreeNode *root , int flag ){
        if(!root)return 0;
        if(mp.count({root,flag}))return mp[{root,flag}];
        int l = 0, r = 0;
        if(!flag){
             l = findMax(root->left,1);
             l+= findMax(root->right,1);
             l+=root->val;
        }
        int nl = findMax(root->left , 0);
        int nr = findMax(root->right, 0);
        return mp[{root,flag}]=max(l,nl+nr);
    }
    int rob(TreeNode* root) {
        return findMax(root,0);
    }
};