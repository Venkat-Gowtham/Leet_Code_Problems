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
    pair<int,int>help(TreeNode *root){
        if(!root)return {0,0};
        if(!root->left and !root->right) {
            int x= root->val;
            return {0,x};
        } 
        auto left  = help(root->left); 
        auto right = help(root->right);
        int temp = root->val;
        return  {left.first+right.first+abs(left.second-right.second),left.second+right.second+temp};
    }
    int findTilt(TreeNode* root ){
        return help(root).first;
    }
};