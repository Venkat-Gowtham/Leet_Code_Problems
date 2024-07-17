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
    int res = INT_MIN;
    int findpath(TreeNode *root){
        if(!root)return INT_MIN;
        if(!root->left and !root->right)return root->val;
        int l = findpath(root->left);
        int r = findpath(root->right);
        if(l!=INT_MIN and r!=INT_MIN) res = max(res,root->val+l+r);
        res=max({res,l,r});
        return max({l!=INT_MIN?l+root->val:root->val,root->val,r!=INT_MIN?root->val+r:root->val});
    }
    int maxPathSum(TreeNode* root) {
        cout<<res;
        return max(res,findpath(root));
    }
};