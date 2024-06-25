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
    int v = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root)return NULL;
        if(!root->left and !root->right){
            if(root->val<v)root->val+=v;
            v=max(root->val,v);
            return root;
        }
        TreeNode * right = bstToGst(root->right);
        if(root->val<v)root->val+=v;
        v=max(v,root->val);
        TreeNode *left   = bstToGst(root->left);
        return root;

    }
};