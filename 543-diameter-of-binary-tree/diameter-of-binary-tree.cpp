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
    int ans = 0;
    int calll(TreeNode * root)
    {
        if(!root) return 0 ;
        int l = calll(root->left);
        int r = calll(root->right);
        ans = max(ans,(l+r));
         return  max(l,r)+1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
      int x = calll(root);
       return ans;
    }
};