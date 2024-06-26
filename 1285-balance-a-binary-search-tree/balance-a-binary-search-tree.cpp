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
    vector<int>res;
    void inorder(TreeNode *root){
        if(!root)return ;
       inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* constructBst(int l , int h){
        if(l>h)return NULL;
        if(l==h) return new TreeNode(res[l]);
        int m = (l+h)/2;
        TreeNode * root = new TreeNode(res[m]);
        root->left = constructBst(l,m-1);
        root->right = constructBst(m+1,h);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return constructBst(0 ,res.size()-1);
    }
};