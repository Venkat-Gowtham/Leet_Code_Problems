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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        // if(!root->left and !root->right) return root->val;
        int l = 0;
        if(root->left && (!root->left->left && !root->left->right)) l+=root->left->val;
       else l = sumOfLeftLeaves(root->left);
        int y = sumOfLeftLeaves(root->right);
        return l+y;
    }
};