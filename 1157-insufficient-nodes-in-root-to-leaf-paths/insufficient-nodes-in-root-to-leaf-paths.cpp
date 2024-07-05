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
    TreeNode* sufficientSubset(TreeNode* root, int limit , int cr = 0) {
        if(!root)return NULL;
        if(!root->left and !root->right){
            return root->val+cr<limit?NULL:root;
        }
       TreeNode* l = sufficientSubset(root->left,limit,cr+root->val);
       TreeNode* r  = sufficientSubset(root->right,limit,cr+root->val);

        if((root->left and !l) and !root->right)return NULL;
        if((root->right and !r) and !root->left) return NULL;
        if(root->left and !l and root->right and !r)return NULL;
        root->left = l;
        root->right = r;
        return root;
    }
};