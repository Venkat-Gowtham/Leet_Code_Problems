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
    void flatten(TreeNode* root) {
        if(!root) return ;
        if(!root->left and !root->right) return ;
        if(!root->right){
            root->right = root->left;
            root->left  = nullptr;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode * temp = root->left , *t=root->right;
        if(temp){root->right = temp ;
        root->left = NULL;}
        while(temp and temp->right)temp=temp->right;
        if(temp)temp ->right = t;
        

    }
};