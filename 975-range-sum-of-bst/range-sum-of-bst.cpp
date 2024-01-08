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
    int findall(TreeNode* root, int low ,int high)
    {
        if(!root)return 0;
        int a=0;
         if(root->val>=low and root->val<=high)
         {
             a+=root->val;
         }
         int x=findall(root->left,low,high);
         int y=findall(root->right,low,high);
         return a+x+y;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
       return findall(root,low,high);
    }
};