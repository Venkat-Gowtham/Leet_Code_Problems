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
    unordered_map<int,int>mp;
    vector<TreeNode*>res;
    TreeNode * findans(TreeNode *root){
        if(!root)return NULL;
        if(!root->left and !root->right){
            return mp.count(root->val)?NULL:root;
        }

        root->left = findans(root->left);
        root->right = findans(root->right);
        if(mp.count(root->val)){
            if(root->left)res.push_back(root->left);
            if(root->right)res.push_back(root->right);
            return NULL;
        }
        // else res.push_back(root);
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        for(auto it : to_delete)mp[it]++;
        TreeNode * ans = findans(root);
        if(!mp.count(root->val))res.push_back(root); 
        return res;

    }
};