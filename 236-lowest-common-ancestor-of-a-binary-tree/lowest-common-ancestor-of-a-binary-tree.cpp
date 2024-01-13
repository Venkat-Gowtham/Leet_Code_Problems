/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
         if(!root)return root;
       if(root==n1 or root==n2)return root;
       
        TreeNode* t1= lowestCommonAncestor(root->left,n1,n2);
        TreeNode* t2= lowestCommonAncestor(root->right,n1,n2);
        if(t1 and t2)
        {
          return root;
        }
      return t1?t1:t2;
    }
};