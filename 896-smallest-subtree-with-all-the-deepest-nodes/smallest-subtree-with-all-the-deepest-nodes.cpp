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
pair<TreeNode*,int>lcsdp(TreeNode *root , int lvl){
        if(!root)return {NULL,0};
        if(!root->left and !root->right){
            return {root,lvl};
        }
        auto lft = lcsdp(root->left , lvl+1);
        auto rgt = lcsdp(root->right, lvl+1);
        if(lft.second == rgt.second){
            return {root,lft.second};
        }
        if(lft.second<rgt.second){
            return rgt;
        }
        else return lft;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root->left and !root->right)return root;
        auto it = lcsdp(root ,0);
        return it.first;
    }
};